const int MAX = 10000;
double xT[MAX], yR[MAX];
int nT;

void loadTemperatureTables() {
  std::ifstream fin( "outputfiles/KT103J2.csv" );
  std::string line;
  nT=0;
  for(;;nT++) {
    if(!std::getline(fin,line)) break;
    if(nT>MAX) break;
    TString rline = line;
    TObjArray *lst = rline.Tokenize(",");
    xT[nT] =  ((TObjString*) lst->At(0))->GetString().Atof();
    yR[nT] =  ((TObjString*) lst->At(1))->GetString().Atof();
    //std::cout << xT[n] << " " << yR[n] << std::endl;                                                                          
  }
  std::cout << "I found " << nT << " calibration points." << std::endl;
  if(nT<10) {
    exit(0);
  }
}

double mintemp(double temp) {
  for(int i=0; i!=nT; ++i) {
    if(yR[i]<temp) {
      //std::cout << yR[i] << std::endl;
      return xT[i];
    }
  }
  return -999;
}

void readtemperature(TString file,
		     double &center, double &error) {
  vector<double> resist;
  std::ifstream fin( Form("outputfiles/%s",file.Data()) );
  std::string line;
  for(;;) {
    if(!std::getline(fin,line)) break;
    TString rline = line;
    TObjArray *lst = rline.Tokenize(",");
    resist.push_back( ((TObjString*) lst->At(1))->GetString().Atof() );
  }
  std::cout << "I read " << resist.size() << " values of temperature " << std::endl;
  sort( resist.begin(), resist.end() );
  double temp1 = resist[0];
  double temp2 = resist[resist.size()-1];
  std::cout << "First value " << temp1 << " last value " << temp2 << std::endl;
  double min = mintemp( temp1 );
  double max = mintemp( temp2 );
  center = 0.5*(min+max);
  error = 0.5*(max-min);
  std::cout << "Temperature range " << min << ", " << max << std::endl;
}

void readfile(TString file,
	      double &landauMean,   double &landauStd,
	      double &straightMean, double &straightStd,
	      double &linearMean,   double &linearStd
	      ) {
  ifstream fin( Form("outputfiles/%s_Fits.txt",file.Data()));
  TString tmp;
  fin >> tmp;
  if(tmp==file) {
    fin >> landauMean   >> landauStd;
    fin >> straightMean >> straightStd;
    fin >> linearMean   >> linearStd;
  } else {
    std::cout << "Something wrong with this file " << file.Data() << std::endl;
    std::cout << tmp.Data() << std::endl;
    exit(0);
  }
}

int temperatureTrendS12572() {
  loadTemperatureTables();
  double xD[100], exD[100];
  double xL[100], exL[100];
  double yLandauMeanL[100];
  double yLandauStdL[100];
  double yLinearMeanL[100];
  double yLinearStdL[100];
  double yLandauMeanD[100];
  double yLandauStdD[100];
  double yLinearMeanD[100];
  double yLinearStdD[100];
  double tmp;


  //dark
  int nD=0;
  readtemperature("20200821_S12572/n30C/dark/S12572-n30C-dark-1-temp.csv",xD[nD],exD[nD]);
  readfile("20200821_S12572/n30C/dark/S12572-n30C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //readtemperature("20200821_S12572/n30C/dark/S12572-n30C-dark-2-temp.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/n30C/dark/S12572-n30C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //
  //readtemperature("20200821_S12572/n20C/dark/S12572-n20C-dark-1-temp.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/n20C/dark/S12572-n20C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //readtemperature("20200821_S12572/n20C/dark/S12572-n20C-dark-2-temp.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/n20C/dark/S12572-n20C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //
  //readtemperature("20200821_S12572/n10C/dark/S12572-n10C-dark-1-temp.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/n10C/dark/S12572-n10C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //readtemperature("20200821_S12572/n10C/dark/S12572-n10C-dark-2-temp.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/n10C/dark/S12572-n10C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //
  //readtemperature("20200821_S12572/zeroC/dark/S12572-0C-1.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/zeroC/dark/S12572-0C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //readtemperature("20200821_S12572/zeroC/dark/S12572-0C-2.csv",xD[nD],exD[nD]);
  //readfile("20200821_S12572/zeroC/dark/S12572-0C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  //nD++;
  //
  readtemperature("20200821_S12572/p10C/dark/dark-1.csv",xD[nD],exD[nD]);
  readfile("20200821_S12572/p10C/dark/S12572-10C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200821_S12572/p10C/dark/dark-2.csv",xD[nD],exD[nD]);
  readfile("20200821_S12572/p10C/dark/S12572-10C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200821_S12572/p10C/dark/8.5C-dark.csv",xD[nD],exD[nD]);
  readfile("20200821_S12572/p10C/dark/S12572-8.5C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200821_S12572/p22C/dark/22C-1.csv",xD[nD],exD[nD]);
  readfile("20200821_S12572/p22C/dark/S12572-22C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200821_S12572/p22C/dark/22C-2.csv",xD[nD],exD[nD]);
  readfile("20200821_S12572/p22C/dark/S12572-22C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  

  
  //light
  int nL=0;
  readtemperature("20200821_S12572/n30C/light/S12572-n30C-light-1-temp.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/n30C/light/S12572-n30C-5.0mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200821_S12572/n30C/light/S12572-n30C-light-2-temp.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/n30C/light/S12572-n30C-5.0mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200821_S12572/n20C/light/S12572-n20C-light-1-temp.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/n20C/light/S12572-n20C-5.5mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200821_S12572/n20C/light/S12572-n20C-light-2-temp.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/n20C/light/S12572-n20C-5.5mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200821_S12572/n10C/light/S12572-n10C-light-1-temp.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/n10C/light/S12572-n10C-6.05mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200821_S12572/n10C/light/S12572-n10C-light-2-temp.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/n10C/light/S12572-n10C-6.05mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200821_S12572/zeroC/light/S12572-0C-orange-1.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/zeroC/light/S12572-0C-6.7mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200821_S12572/zeroC/light/S12572-0C-orange-2.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/zeroC/light/S12572-0C-6.7mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200821_S12572/p10C/light/8.5C-1.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/p10C/light/S12572-8.5C-7.3mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200821_S12572/p10C/light/8.5C-2.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/p10C/light/S12572-8.5C-7.3mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200821_S12572/p10C/light/10C-1.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/p10C/light/S12572-10C-8.6mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  //readtemperature("20200821_S12572/p22C/light/22C-1.csv",xL[nL],exL[nL]);
  //readfile("20200821_S12572/p22C/light/S12572-22C-8.6mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  //nL++;
  readtemperature("20200821_S12572/p22C/light/22C-2.csv",xL[nL],exL[nL]);
  readfile("20200821_S12572/p22C/light/S12572-22C-8.6mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////

  
  gStyle->SetOptStat(0);
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+24,100,62,68);
  axis->GetYaxis()->SetNdivisions(509);
  axis->Draw();
  
  TF1 *fit1 = new TF1("fit1","[0]+[1]*x");
  TF1 *fit2 = new TF1("fit2","[0]+[1]*x");  
  TF1 *fit3 = new TF1("fit3","[0]+[1]*x");  
  TF1 *fit4 = new TF1("fit4","[0]+[1]*x");  
  fit1->SetLineColor(kCyan-3);
  fit2->SetLineColor(kGreen-3);
  fit3->SetLineColor(kOrange-3);
  fit4->SetLineColor(kRed-3);
  
  TGraphErrors *grLandauD = new TGraphErrors(nD, xD, yLandauMeanD, exD, yLandauStdD);
  grLandauD->SetMarkerColor( kCyan-3 );
  grLandauD->SetLineColor( kCyan-3 );
  grLandauD->SetMarkerStyle( 20 );
  grLandauD->Draw("PSAME");
  grLandauD->Fit(fit1,"WW");
  
  TGraphErrors *grLinearD = new TGraphErrors(nD, xD, yLinearMeanD, exD, yLinearStdD);
  grLinearD->SetMarkerColor( kGreen-3 );
  grLinearD->SetLineColor( kGreen-3 );
  grLinearD->SetMarkerStyle( 21 );
  grLinearD->Draw("PSAME");
  grLinearD->Fit(fit2,"WW");

  TGraphErrors *grLandauL = new TGraphErrors(nL, xL, yLandauMeanL, exL, yLandauStdL);
  grLandauL->SetMarkerColor( kOrange-3 );
  grLandauL->SetLineColor( kOrange-3 );
  grLandauL->SetMarkerStyle( 22 );
  grLandauL->Draw("PSAME");
  grLandauL->Fit(fit3,"WW");
  
  TGraphErrors *grLinearL = new TGraphErrors(nL, xL, yLinearMeanL, exL, yLinearStdL);
  grLinearL->SetMarkerColor( kRed-3 );
  grLinearL->SetLineColor( kRed-3 );
  grLinearL->SetMarkerStyle( 23 );
  grLinearL->Draw("PSAME");
  grLinearL->Fit(fit4,"WW");

  double nx[1] = {23.5};
  double ny[1] = {38.4};
  double enx[1] = {0};
  double eny[1] = {0.1};
  TGraphErrors *nominal = new TGraphErrors(1,nx,ny,enx,eny);
  nominal->Draw("*SAME");
  
  TLegend *leg = new TLegend(0.51,0.16,0.84,0.35);
  leg->AddEntry(grLandauD,Form("DARK:: Max dLnI/dV: %.0f mV/deg",fit1->GetParameter(1)*1e3));
  leg->AddEntry(grLinearD,Form("DARK:: Xing sqrtI: %.0f mV/deg",fit2->GetParameter(1)*1e3));
  leg->AddEntry(grLandauL,Form("LED:: Max dLnI/dV: %.0f mV/deg",fit3->GetParameter(1)*1e3));
  leg->AddEntry(grLinearL,Form("LED:: Xing sqrtI: %.0f mV/deg",fit4->GetParameter(1)*1e3));
  leg->Draw();
  
  return 0;
}
