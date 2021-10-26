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

int temperatureTrendNewSiPM1() {
  double n30_1_landauMean, n30_1_landauStd, n30_1_straightMean, n30_1_straightStd, n30_1_linearMean, n30_1_linearStd;
  readfile("20200811_n30C/HDR2-_Chdirect_iLED-1-20200811-1303.csv",
	   n30_1_landauMean,  n30_1_landauStd,
	   n30_1_straightMean,n30_1_straightStd,
	   n30_1_linearMean,  n30_1_linearStd );
  double n30_2_landauMean, n30_2_landauStd, n30_2_straightMean, n30_2_straightStd, n30_2_linearMean, n30_2_linearStd;
  readfile("20200811_n30C/HDR2-_Chdirect_iLED-1-20200811-1306.csv",
	   n30_2_landauMean,  n30_2_landauStd,
	   n30_2_straightMean,n30_2_straightStd,
	   n30_2_linearMean,  n30_2_linearStd );

  double n19_1_landauMean, n19_1_landauStd, n19_1_straightMean, n19_1_straightStd, n19_1_linearMean, n19_1_linearStd;
  readfile("20200811_n19C/HDR2-_Chdirect_iLED-1-20200810-1646.csv",
	   n19_1_landauMean,  n19_1_landauStd,
	   n19_1_straightMean,n19_1_straightStd,
	   n19_1_linearMean,  n19_1_linearStd );
  double n19_2_landauMean, n19_2_landauStd, n19_2_straightMean, n19_2_straightStd, n19_2_linearMean, n19_2_linearStd;
  readfile("20200811_n19C/HDR2-_Chdirect_iLED-1-20200810-1649.csv",
	   n19_2_landauMean,  n19_2_landauStd,
	   n19_2_straightMean,n19_2_straightStd,
	   n19_2_linearMean,  n19_2_linearStd );

  double n1617_1_landauMean, n1617_1_landauStd, n1617_1_straightMean, n1617_1_straightStd, n1617_1_linearMean, n1617_1_linearStd;
  readfile("20200811_n1617C/HDR2-_Chdirect_iLED-1-20200810-1631.csv",
	   n1617_1_landauMean,  n1617_1_landauStd,
	   n1617_1_straightMean,n1617_1_straightStd,
	   n1617_1_linearMean,  n1617_1_linearStd );
  double n1617_2_landauMean, n1617_2_landauStd, n1617_2_straightMean, n1617_2_straightStd, n1617_2_linearMean, n1617_2_linearStd;
  readfile("20200811_n1617C/HDR2-_Chdirect_iLED-1-20200810-1634.csv",
	   n1617_2_landauMean,  n1617_2_landauStd,
	   n1617_2_straightMean,n1617_2_straightStd,
	   n1617_2_linearMean,  n1617_2_linearStd );  

  double n10_1_landauMean, n10_1_landauStd, n10_1_straightMean, n10_1_straightStd, n10_1_linearMean, n10_1_linearStd;
  readfile("20200811_n10C/HDR2-_Chdirect_iLED-1-20200810-1601.csv",
	   n10_1_landauMean,  n10_1_landauStd,
	   n10_1_straightMean,n10_1_straightStd,
	   n10_1_linearMean,  n10_1_linearStd );
  double n10_2_landauMean, n10_2_landauStd, n10_2_straightMean, n10_2_straightStd, n10_2_linearMean, n10_2_linearStd;
  readfile("20200811_n10C/HDR2-_Chdirect_iLED-1-20200810-1607.csv",
	   n10_2_landauMean,  n10_2_landauStd,
	   n10_2_straightMean,n10_2_straightStd,
	   n10_2_linearMean,  n10_2_linearStd );  
  double n10_3_landauMean, n10_3_landauStd, n10_3_straightMean, n10_3_straightStd, n10_3_linearMean, n10_3_linearStd;
  readfile("20200811_n10C/HDR2-_Chdirect_iLED-1-20200810-1609.csv",
	   n10_3_landauMean,  n10_3_landauStd,
	   n10_3_straightMean,n10_3_straightStd,
	   n10_3_linearMean,  n10_3_linearStd );  

  double p0102_1_landauMean, p0102_1_landauStd, p0102_1_straightMean, p0102_1_straightStd, p0102_1_linearMean, p0102_1_linearStd;
  readfile("20200811_p0102C/HDR2-_Chdirect_iLED-1-20200810-1452.csv",
	   p0102_1_landauMean,  p0102_1_landauStd,
	   p0102_1_straightMean,p0102_1_straightStd,
	   p0102_1_linearMean,  p0102_1_linearStd );
  double p0102_2_landauMean, p0102_2_landauStd, p0102_2_straightMean, p0102_2_straightStd, p0102_2_linearMean, p0102_2_linearStd;
  readfile("20200811_p0102C/HDR2-_Chdirect_iLED-1-20200810-1455.csv",
	   p0102_2_landauMean,  p0102_2_landauStd,
	   p0102_2_straightMean,p0102_2_straightStd,
	   p0102_2_linearMean,  p0102_2_linearStd );  
  double p0102_3_landauMean, p0102_3_landauStd, p0102_3_straightMean, p0102_3_straightStd, p0102_3_linearMean, p0102_3_linearStd;
  readfile("20200811_p0102C/HDR2-_Chdirect_iLED-1-20200810-1458.csv",
	   p0102_3_landauMean,  p0102_3_landauStd,
	   p0102_3_straightMean,p0102_3_straightStd,
	   p0102_3_linearMean,  p0102_3_linearStd );  

  
  double x[100], ex[100];
  double yLandauMean[100];
  double yLandauStd[100];
  double yLinearMean[100];
  double yLinearStd[100];

  x[0] = 0.5*(-31.25 -31.15);
  ex[0] = 0.5*(+31.25 -31.15);
  yLandauMean[0] = n30_1_landauMean;
  yLandauStd[0] = n30_1_landauStd;
  yLinearMean[0] = n30_1_linearMean;
  yLinearStd[0] = n30_1_linearStd;
  x[1] = 0.5*(-31.25 -31.15);
  ex[1] = 0.5*(+31.25 -31.15);
  yLandauMean[1] = n30_2_landauMean;
  yLandauStd[1] = n30_2_landauStd;
  yLinearMean[1] = n30_2_linearMean;
  yLinearStd[1] = n30_2_linearStd;

  x[2] = 0.5*(-18.9 -18.65);
  ex[2] = 0.5*(+18.9 -18.65);
  yLandauMean[2] = n19_1_landauMean;
  yLandauStd[2] = n19_1_landauStd;
  yLinearMean[2] = n19_1_linearMean;
  yLinearStd[2] = n19_1_linearStd;
  x[3] = 0.5*(-18.9 -18.65);
  ex[3] = 0.5*(+18.9 -18.65);
  yLandauMean[3] = n19_2_landauMean;
  yLandauStd[3] = n19_2_landauStd;
  yLinearMean[3] = n19_2_linearMean;
  yLinearStd[3] = n19_2_linearStd;

  x[4] = 0.5*(-16.85 -16.05);
  ex[4] = 0.5*(+16.85 -16.05);
  yLandauMean[4] = n1617_1_landauMean;
  yLandauStd[4] = n1617_1_landauStd;
  yLinearMean[4] = n1617_1_linearMean;
  yLinearStd[4] = n1617_1_linearStd;
  x[5] = 0.5*(-16.85 -16.05);
  ex[5] = 0.5*(+16.85 -16.05);
  yLandauMean[5] = n1617_2_landauMean;
  yLandauStd[5] = n1617_2_landauStd;
  yLinearMean[5] = n1617_2_linearMean;
  yLinearStd[5] = n1617_2_linearStd;

  x[6] = 0.5*(-9.7 -9.1);
  ex[6] = 0.5*(+9.7 -9.1);
  yLandauMean[6] = n10_1_landauMean;
  yLandauStd[6] = n10_1_landauStd;
  yLinearMean[6] = n10_1_linearMean;
  yLinearStd[6] = n10_1_linearStd;
  x[7] = 0.5*(-9.7 -9.1);
  ex[7] = 0.5*(+9.7 -9.1);
  yLandauMean[7] = n10_2_landauMean;
  yLandauStd[7] = n10_2_landauStd;
  yLinearMean[7] = n10_2_linearMean;
  yLinearStd[7] = n10_2_linearStd;
  x[8] = 0.5*(-9.7 -9.1);
  ex[8] = 0.5*(+9.7 -9.1);
  yLandauMean[8] = n10_3_landauMean;
  yLandauStd[8] = n10_3_landauStd;
  yLinearMean[8] = n10_3_linearMean;
  yLinearStd[8] = n10_3_linearStd;

  x[9] = 0.5*(+1.7 +1.9);
  ex[9] = 0.5*(-1.7 +1.9);
  yLandauMean[9] = p0102_1_landauMean;
  yLandauStd[9] = p0102_1_landauStd;
  yLinearMean[9] = p0102_1_linearMean;
  yLinearStd[9] = p0102_1_linearStd;
  x[10] = 0.5*(+1.7 +1.9);
  ex[10] = 0.5*(-1.7 +1.9);
  yLandauMean[10] = p0102_2_landauMean;
  yLandauStd[10] = p0102_2_landauStd;
  yLinearMean[10] = p0102_2_linearMean;
  yLinearStd[10] = p0102_2_linearStd;
  x[11] = 0.5*(+1.7 +1.9);
  ex[11] = 0.5*(-1.7 +1.9);
  yLandauMean[11] = p0102_3_landauMean;
  yLandauStd[11] = p0102_3_landauStd;
  yLinearMean[11] = p0102_3_linearMean;
  yLinearStd[11] = p0102_3_linearStd;
  
  gStyle->SetOptStat(0);
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+10,100,36,42);
  axis->GetYaxis()->SetNdivisions(509);
  axis->Draw();
  
  TF1 *fit1 = new TF1("fit1","[0]+[1]*x");
  TF1 *fit2 = new TF1("fit2","[0]+[1]*x");  
  fit1->SetLineColor(kCyan-3);
  fit2->SetLineColor(kGreen-3);
  
  TGraphErrors *grLandau = new TGraphErrors(12, x, yLandauMean, ex, yLandauStd);
  grLandau->SetMarkerColor( kCyan-3 );
  grLandau->SetLineColor( kCyan-3 );
  grLandau->SetMarkerStyle( 20 );
  grLandau->Draw("PSAME");
  grLandau->Fit(fit1);
  
  TGraphErrors *grLinear = new TGraphErrors(12, x, yLinearMean, ex, yLinearStd);
  grLinear->SetMarkerColor( kGreen-3 );
  grLinear->SetLineColor( kGreen-3 );
  grLinear->SetMarkerStyle( 20 );
  grLinear->Draw("PSAME");
  grLinear->Fit(fit2);
  
  TLegend *leg = new TLegend(0.55,0.37,0.87,0.56);
  leg->AddEntry(grLandau,Form("Max dLnI/dV: %.0f mV/deg",fit1->GetParameter(1)*1e3));
  leg->AddEntry(grLinear,Form("Xing sqrtI: %.0f mV/deg",fit2->GetParameter(1)*1e3));
  leg->Draw();
  
  return 0;
}
