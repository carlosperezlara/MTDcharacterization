const int MAX=1000;

void primeit(
	     double x[MAX], double y[MAX],
	     double xp[MAX], double yp[MAX],
	     int n, bool norm=false) {
  for(int i=1; i!=n-1; ++i) {
    double den = x[i+1] - x[i-1];
    double num = y[i+1] - y[i-1];
    xp[i-1] = x[i];
    yp[i-1] = num/den;
    if(norm) yp[i-1] /= y[i];
    //std::cout << x[i] << " " << y[i] << "|" << xp[i-1] << " " << yp[i-1] << std::endl;
  }
  return;
}

double threshold(
		 int xstart, int xstop,
		 double y[MAX], double thr,
		 bool rising) {
  int ret = -999;
  for(int i=xstart; i<=xstop; ++i)
    if(rising&&y[i]>thr) {
      ret = i;
      break;
    } else if(!rising&&y[i]<thr) {
      ret = i;
      break;
    }
  return ret;
}

double rising(
	      int xstart, int xstop,
	      double y[MAX], double thr ) {
  return threshold( xstart, xstop, y, thr, true);
}

int falling(
	       int xstart, int xstop,
	       double y[MAX], double thr ) {
  return threshold( xstart, xstop, y, thr, false);
}

int peak(
	 int xstart, int xstop,
	 double y[MAX], double &max) {
  int ret = -999;
  max = -999;
  for(int i=xstart; i<xstop; ++i)
    if(y[i]>max) {
      max = y[i];
      ret = i;
    }
  return ret;
}

double floor(
	 int xstart, int xstop,
	 double y[MAX]) {
  double ret = 999;
  for(int i=xstart; i<xstop; ++i)
    if(y[i]<ret)
      ret = y[i];
  return ret;
}

 int compress(int n, double x[MAX], double y[MAX], double xx[MAX], double yy[MAX], double thr=0.1) {
  int nn = 0;
  for(int i=0; i<n; ++i) {
    xx[nn] = x[i];
    yy[nn] = y[i];
    if(i<n-1)
      if(x[i+1]-x[i]<thr) { // less than 100 mV -> merge
	xx[nn] = 0.5*(x[i] + x[i+1]);
	yy[nn] = 0.5*(y[i] + y[i+1]);
	i++;
      }
    nn++;
  }
  return nn;
}


//int bvfinder(TString file="SiPM-X1_Chdirect_iLED-1-20200720-1454.csv"
//int bvfinder(TString file="SiPM-X1_Chdirect_iLED-1-20200723-1030.csv",
//int bvfinder(TString file="SiPM-HDR2_Chdirect_ambient-20200727-1510.csv",
//int bvfinder(TString file="SiPM-HDR2_Chdirect_iLED-1-20200727-1517.csv",
//int bvfinder(TString file="SiPM-HDR2_Chdirect_iLED-1-20200729-0948.csv",
//int bvfinder(TString file="SiPM-HDR2_Chdirect_ambient-20200727-1510.csv",
//int bvfinder(TString file="SiPM-HDR2-2_Chdirect_iLED-1-20200729-1323.csv",
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch4_iLED-1-20200804-1054.csv", //20.8C someone turn on the lights =(
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch4_iLED-1-20200804-1110.csv", //20.8C looks fine
int bvfinder(TString file="20200804_20.8C/HDR2-_Ch4_iLED-1-20200804-1122.csv", //20.8C looks fine too
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch4_iLED-1-20200804-1128.csv", //20.8C looks fine (no lights)
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch6_iLED-1-20200804-1058.csv", //20.8C someone turn on the lights =(
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch6_iLED-1-20200804-1113.csv", //20.8C looks fine
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch6_iLED-1-20200804-1118.csv", //20.8C looks fine too
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch6_iLED-1-20200804-1131.csv", //20.8C few outliers (no lights)
//int bvfinder(TString file="20200804_20.8C/HDR2-_Ch6_iLED-1-20200804-1135.csv", //20.8C looks fine (no lights)
	     //double merge=0.1, double xdiff=1,
	     double merge=0.05, double xdiff=0,
	     double thrPrime=0.5 ) {
  gStyle->SetOptStat(0);
  int n=0;
  double volt[MAX];
  double curr[MAX];
  double volt0[MAX];
  double curr0[MAX];
  double volt1[MAX];
  double curr1[MAX];
  double volt2[MAX];
  double curr2[MAX];
  double sqrtc[MAX];
  
  ///////
  // my clumsy way of extracting data from a csv file
  TString outfilestring = Form("outputfiles/%s",file.Data());
  std::ifstream fin( outfilestring.Data() );
  std::string line;
  for(;;n++) {
    if(!std::getline(fin,line)) break;
    if(n>MAX) break;
    TString rline = line;
    TObjArray *lst = rline.Tokenize(",");
    volt[n] =  ((TObjString*) lst->At(0))->GetString().Atof();
    curr[n] =  ((TObjString*) lst->At(1))->GetString().Atof()*1e6; // move to uA
  }
  // dont go below 50mV steps
  int nn = 0;
  std::cout << "**** nn=" << nn << std::endl;
  double xtemp1[MAX], xtemp2[MAX];
  double ytemp1[MAX], ytemp2[MAX];
  nn = compress(n,volt,curr,xtemp1,ytemp1,merge);
  std::cout << "**** nn=" << nn << std::endl;
  nn = compress(nn,xtemp1,ytemp1,xtemp2,ytemp2,merge);
  std::cout << "**** nn=" << nn << std::endl;
  nn = compress(nn,xtemp2,ytemp2,xtemp1,ytemp1,merge);
  std::cout << "**** nn=" << nn << std::endl;
  nn = compress(nn,xtemp1,ytemp1,xtemp2,ytemp2,merge);
  std::cout << "**** nn=" << nn << std::endl;
  nn = compress(nn,xtemp2,ytemp2,xtemp1,ytemp1,merge);
  std::cout << "**** nn=" << nn << std::endl;
  nn = compress(nn,xtemp1,ytemp1,xtemp2,ytemp2,merge);
  std::cout << "**** nn=" << nn << std::endl;
  nn = compress(nn,xtemp2,ytemp2,volt0,curr0,merge);
  std::cout << "**** nn=" << nn << std::endl;
  
  // transforming
  for(int i=0; i!=n; ++i) {
    curr[i] *= 1e3; // move to nA
  }
  for(int i=0; i!=nn; ++i) {
    sqrtc[i] =  TMath::Sqrt(curr0[i]); // sqrt of current
    curr0[i] *= 1e3; // move to nA
  }

  ///////
  std::cout << "I read " << n << " pairs. My MAX stack was " << MAX << std::endl;
  
  //primeit(volt, curr, volt1,curr1,n,true);
  //primeit(volt1,curr1,volt2,curr2,n-2);
  primeit(volt0,curr0,volt1,curr1,nn,true);
  primeit(volt1,curr1,volt2,curr2,nn-2);
  
  int skipfirst = 10;
  // finding first peak of primed
  int xini = rising(skipfirst,nn-1,curr1,thrPrime);
  int xend = falling(xini,nn-1,curr1,thrPrime);
  std::cout << "Found potential range from " << volt1[xini] << " and " << volt1[xend] << std::endl;
  double thr;
  int xpea = peak(xini,xend,curr1,thr);
  std::cout << "first peak found at " << thr << std::endl;
  xini = rising(skipfirst,xpea,curr1,0.68*thr);
  xend = falling(xpea,nn-1,curr1,0.68*thr);
  std::cout << "Found potential range from " << volt1[xini] << " and " << volt1[xend] << std::endl;

  // create graphical objects
  TGraph *gr0 = new TGraph(n,volt,curr);
  TGraph *gr00 = new TGraph(nn,volt0,curr0);
  TGraph *gr1 = new TGraph(nn-2,volt1,curr1);
  TGraph *gr2 = new TGraph(nn-4,volt2,curr2);
  TGraph *gr3 = new TGraph(nn,volt0,sqrtc);

  // estimating inflection point from primedTwo
  double mid = 0.5*(volt1[xend]+volt1[xini]);
  //TF1 *fitStraight = new TF1("fitStraight", Form("[0]+[1]*(x-%f)+[2]*pow(x-%f,3)",mid,mid), volt1[xini], volt1[xend] );
  //TF1 *fitStraight = new TF1("fitStraight", Form("[0]+[1]*(x-%f)",mid), volt1[xini], volt1[xini]+1 );
  TF1 *fitStraight = new TF1("fitStraight", Form("[0]+[1]*(x-%f)",mid), volt1[xini], volt1[xini]+1 );
  fitStraight->SetParameter(1,-10);
  fitStraight->SetParLimits(1,-1e6,0);
  gr2->Fit( fitStraight, "WWRQ", "", volt1[xini], volt1[xini]+0.6 );
  double estimator1=fitStraight->GetX(0);
  std::cout << "Inflection point estimated at " << estimator1 << std::endl;

// estimating crossing point with zero
  TF1 *fitLinear = new TF1("fitLinear","[0]+[1]*x", estimator1+xdiff, estimator1+xdiff+2);
  fitLinear->SetLineColor( kBlue-3 );
  fitLinear->SetLineWidth(4);
  gr3->Fit( fitLinear, "WWRQ", "", estimator1+xdiff, estimator1+xdiff+2 );
  TF1 *fitLinear2 = new TF1("fitLinear2",Form("%f+%f*x",fitLinear->GetParameter(0),
					      fitLinear->GetParameter(1)),0,volt1[xend]);
  double estimator2=fitLinear2->GetX(0);
  std::cout << "Crossing estimated at " << estimator2 << std::endl;
  fitLinear2->SetLineColor( kBlue-3 );
  fitLinear2->SetLineStyle( 2 );


  /////////////
  // D O N E //
  /////////////

  
  ///////
  // display all
  double max0, max3, min0, min3;
  peak(0,nn,curr0, max0);
  peak(0,nn,sqrtc,max3);
  min0 = floor(0,nn,curr0);
  min3 = floor(2,nn,curr0);
  TLine *lin = new TLine();
  lin->SetLineColor(kRed-3);
  TLatex *tex = new TLatex();
  std::cout << "min " << min0 << " max0 " << max0 << std::endl;

  TCanvas *main = new TCanvas();
  main->cd()->SetLogy(1);
  TH2D *axis0 = new TH2D("axis0","IV-curve;Bias (V);I  (nA)",100,0, volt[n-1]+2,10000,min0,max0);
  axis0->Draw("");
  gr0->Draw("*SAME");
  gr0->SetMarkerColor(kGreen-3);
  gr00->Draw("*SAME");
  gr0->GetYaxis()->SetTitle("I (nA)");
  gr0->GetXaxis()->SetTitle("Bias (V)");
  tex->SetTextSize(0.03);
  tex->DrawTextNDC(0.12,0.85,Form("%s",file.Data()));
  tex->SetTextSize(0.05);
  main->SaveAs( Form("%s_Fig0.pdf",outfilestring.Data()), "pdf" );
  
  TCanvas *main1 = new TCanvas();
  main1->Divide(2,1);
  main1->cd(1);
  gr1->Draw("A*");
  lin->DrawLine(volt1[xini],-1,volt1[xini],+10);
  lin->DrawLine(volt1[xend],-1,volt1[xend],+10);
  gr1->GetXaxis()->SetRangeUser( volt1[xini]-2, volt1[xend]+2);
  main1->cd(2);
  gr2->Draw("A*");
  //lin->DrawLine(volt1[xini],-1,volt1[xini],+10);
  //lin->DrawLine(volt1[xend],-1,volt1[xend],+10);
  gr2->GetXaxis()->SetRangeUser( volt1[xini]-2, volt1[xend]+2);
  tex->SetTextColor(kRed-3);
  tex->DrawText(estimator1,0,Form("%.2f",estimator1));

  gr1->GetYaxis()->SetTitle("(dI / dV)  /  I");
  gr1->GetXaxis()->SetTitle("Bias (V)");
  gr2->GetYaxis()->SetTitle("(d^{2} I / dV^{2})  /  I");
  gr2->GetXaxis()->SetTitle("Bias (V)");
  gr1->SetTitle("");
  gr2->SetTitle("");
  main1->SaveAs( Form("%s_Fig1.pdf",outfilestring.Data()), "pdf" );
  
  TCanvas *main2 = new TCanvas();
  TH2D *axis3 = new TH2D("axis3",";Bias (V);#sqrt{I}  (uA)", 100, volt1[xini]-2, volt1[xend]+2,10000,0,max3);
  axis3->Draw("");
  gr3->Draw("*SAME");
  fitLinear2->Draw("same");
  fitLinear->Draw("same");
  tex->SetTextColor(kBlue-3);
  tex->DrawText(estimator2,0,Form("%.2f",estimator2));
  main2->SaveAs( Form("%s_Fig2.pdf",outfilestring.Data()), "pdf" );
  
  TCanvas *main3 = new TCanvas();
  main3->SetLogy(1);
  gr0->Draw("A*");
  gr0->SetTitle("IV-curve");
  gr0->GetXaxis()->SetRangeUser( volt1[xini]-2, volt1[xend]+2);
  gr0->GetYaxis()->SetRangeUser( min3, max0 );
  lin->SetLineColor(kRed-3);
  lin->DrawLine(estimator1,-1,estimator1,+1);
  tex->SetTextColor(kRed-3);
  tex->DrawText(estimator1,-1,Form("%.2f",estimator1));
  lin->SetLineColor(kBlue-3);
  lin->DrawLine(estimator2,-1,estimator2,+1);
  tex->SetTextColor(kBlue-3);
  tex->DrawText(estimator2,-1,Form("%.2f",estimator2));
  main3->SaveAs( Form("%s_Fig3.pdf",outfilestring.Data()), "pdf" );



  ///////
  
  return 0;
}
