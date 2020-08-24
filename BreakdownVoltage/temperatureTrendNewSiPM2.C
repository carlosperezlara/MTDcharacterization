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

int temperatureTrendNewSiPM2() {
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

  int nL=0;
  int nD=0;

  /////////////////
  // -30 C;
  /////////////////

  //dark
  xD[nD] = 0.5*(-29.30 -28.90);
  exD[nD] = 0.5*(+29.30 -28.90);
  readfile("20200815_n30C/dark/HDR2-2-n30C-dark-1.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-29.75 -29.35);
  exD[nD] = 0.5*(+29.75 -39.35);
  readfile("20200815_n30C/dark/HDR2-2-n30C-dark-2.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-30.55 -30.05);
  exD[nD] = 0.5*(+30.55 -30.05);
  readfile("20200815_n30C/dark/HDR2-2-n30C-dark-3.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //light
  xL[nL] = 0.5*(-30.75 -30.55);
  exL[nL] = 0.5*(+30.75 -30.55);
  readfile("20200815_n30C/light/HDR2-2-n30C-5.9mA-Orange-1.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-30.60 -30.40);
  exL[nL] = 0.5*(+30.60 -30.40);
  readfile("20200815_n30C/light/HDR2-2-n30C-5.9mA-Orange-2.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-30.35 -30.05);
  exL[nL] = 0.5*(+30.35 -30.05);
  readfile("20200815_n30C/light/HDR2-2-n30C-5.9mA-Orange-3.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;

  /////////////////
  // -20 C;
  /////////////////

  //dark
  xD[nD] = 0.5*(-19.55 -19.40);
  exD[nD] = 0.5*(+19.55 -19.40);
  readfile("20200815_n20C/dark/HDR2-2-n20C-dark-1.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-20.80 -20.60);
  exD[nD] = 0.5*(+20.80 -20.60);
  readfile("20200815_n20C/dark/HDR2-2-n20C-dark-2.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-20.80 -20.65);
  exD[nD] = 0.5*(+20.80 -20.65);
  readfile("20200815_n20C/dark/HDR2-2-n20C-dark-3.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //light
  xL[nL] = 0.5*(-19.95 -19.50);
  exL[nL] = 0.5*(+19.95 -19.50);
  readfile("20200815_n20C/light/HDR2-2-n20C-6.5mA-Orange-1.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-19.55 -19.35);
  exL[nL] = 0.5*(+19.55 -19.35);
  readfile("20200815_n20C/light/HDR2-2-n20C-6.5mA-Orange-2.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-19.55 -19.40);
  exL[nL] = 0.5*(+19.55 -19.40);
  readfile("20200815_n20C/light/HDR2-2-n20C-6.5mA-Orange-3.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;

  /////////////////
  // -10 C;
  /////////////////

  //dark
  xD[nD] = 0.5*(-10.30 -10.05);
  exD[nD] = 0.5*(+10.30 -10.05);
  readfile("20200815_n10C/dark/HDR2-2-n10C-dark-1.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-9.45 -9.30);
  exD[nD] = 0.5*(+9.45 -9.30);
  readfile("20200815_n10C/dark/HDR2-2-n10C-dark-2.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-9.95 -9.20);
  exD[nD] = 0.5*(+9.95 -9.20);
  readfile("20200815_n10C/dark/HDR2-2-n10C-dark-3.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //light
  xL[nL] = 0.5*(-10.70 -10.60);
  exL[nL] = 0.5*(+10.70 -10.60);
  readfile("20200815_n10C/light/HDR2-2-n10C-7mA-Orange-1.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-10.50 -10.35);
  exL[nL] = 0.5*(+10.50 -10.35);
  readfile("20200815_n10C/light/HDR2-2-n10C-7mA-Orange-2.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-10.40 -10.05);
  exL[nL] = 0.5*(+10.40 -10.05);
  readfile("20200815_n10C/light/HDR2-2-n10C-7mA-Orange-3.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;

  /////////////////
  // zero C;
  /////////////////

  //dark
  xD[nD] = 0.5*(0.35 +0.95);
  exD[nD] = 0.5*(-0.35 +0.95);
  readfile("20200815_zeroC/dark/HDR2-2-0C-dark-1.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-0.35 -0.10);
  exD[nD] = 0.5*(+0.35 -0.10);
  readfile("20200815_zeroC/dark/HDR2-2-0C-dark-2.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(-0.35 -0.30);
  exD[nD] = 0.5*(+0.35 -0.30);
  readfile("20200815_zeroC/dark/HDR2-2-0C-dark-3.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //light
  xD[nL] = 0.5*(-1.10 -1.30);
  exD[nL] = 0.5*(+1.10 -1.30);
  readfile("20200815_zeroC/light/HDR2-2-0C-7.8mA-Orange-1.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-0.45 -0.80);
  exL[nL] = 0.5*(+0.45 -0.80);
  readfile("20200815_zeroC/light/HDR2-2-0C-7.8mA-Orange-2.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(-0.10 -0.25);
  exL[nL] = 0.5*(+0.10 -0.25);
  readfile("20200815_zeroC/light/HDR2-2-0C-7.8mA-Orange-3.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;

  /////////////////
  // +10 C;
  /////////////////

  //dark
  xD[nD] = 0.5*(+10.15 +10.60);
  exD[nD] = 0.5*(-10.15 +10.60);
  readfile("20200815_p10C/HDR2-2-10C-dark.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(+10.15 +10.60);
  exD[nD] = 0.5*(-10.15 +10.60);
  readfile("20200815_p10C/HDR2-2-10C-dark-2.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;

  //light

  xL[nL] = 0.5*(+10.05 +10.25);
  exL[nL] = 0.5*(-10.05 +10.25);
  readfile("20200815_p10C/HDR2-2-10C-10mA-Orange.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(+10.05 +10.25);
  exL[nL] = 0.5*(-10.05 +10.25);
  readfile("20200815_p10C/HDR2-2-10C-10mA-Orange-2.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;

  xL[nL] = 0.5*(+10.05 +10.25);
  exL[nL] = 0.5*(-10.05 +10.25);
  readfile("20200815_p10C/HDR2-2-10C-10mA-Orange-3.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;

  /////////////////
  // +20 C;
  /////////////////
  
  //dark
  xD[nD] = 0.5*(+20.65 +20.70);
  exD[nD] = 0.5*(-20.65 +20.70);
  readfile("20200815_p20C/dark/HDR2-2-20C-_Chdirect_iLED-1-20200813-1406.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  xD[nD] = 0.5*(+20.65 +20.70);
  exD[nD] = 0.5*(-20.65 +20.70);
  readfile("20200815_p20C/dark/HDR2-2-20C-_Chdirect_iLED-1-20200813-1408.csv",
	   yLandauMeanD[nD], yLandauStdD[nD],
	   tmp, tmp,
	   yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;

  //light
  xL[nL] = 0.5*(+20.90 +21.15);
  exL[nL] = 0.5*(-20.90 +21.15);
  readfile("20200815_p20C/light/HDR2-2-20C-10mA-Orange.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  xL[nL] = 0.5*(+20.90 +21.15);
  exL[nL] = 0.5*(-20.90 +21.15);
  readfile("20200815_p20C/light/HDR2-2-20C-10mA-Orange-2.csv",
	   yLandauMeanL[nL], yLandauStdL[nL],
	   tmp, tmp,
	   yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;  
  
  gStyle->SetOptStat(0);
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+24,100,36,40.5);
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
  grLandauD->Fit(fit1);
  
  TGraphErrors *grLinearD = new TGraphErrors(nD, xD, yLinearMeanD, exD, yLinearStdD);
  grLinearD->SetMarkerColor( kGreen-3 );
  grLinearD->SetLineColor( kGreen-3 );
  grLinearD->SetMarkerStyle( 21 );
  grLinearD->Draw("PSAME");
  grLinearD->Fit(fit2);

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
  
  TLegend *leg = new TLegend(0.14,0.67,0.47,0.86);
  leg->AddEntry(grLandauD,Form("DARK:: Max dLnI/dV: %.0f mV/deg",fit1->GetParameter(1)*1e3));
  leg->AddEntry(grLinearD,Form("DARK:: Xing sqrtI: %.0f mV/deg",fit2->GetParameter(1)*1e3));
  leg->AddEntry(grLandauL,Form("LED:: Max dLnI/dV: %.0f mV/deg",fit3->GetParameter(1)*1e3));
  leg->AddEntry(grLinearL,Form("LED:: Xing sqrtI: %.0f mV/deg",fit4->GetParameter(1)*1e3));
  leg->Draw();
  
  return 0;
}
