#include "helpers.C"

int currentTrendHDR2e14() {
  loadTemperatureTables();
  double xD[100], exD[100];
  double xL[100], exL[100];
  double yL[100], eyL[100];
  for(int i=100;i!=100;++i) eyL[i]=0;
  double tmp;

  //dark
  int nD=0;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-1.csv", tmp, yL[nD] );
  nD++;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-2.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-2.csv", tmp, yL[nD] );
  nD++;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-3.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-3.csv", tmp, yL[nD] );
  nD++;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-4.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-4.csv", tmp, yL[nD] );
  nD++;
  //
  readtemperature("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-temps-1.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-1.csv", tmp, yL[nD] );
  nD++;
  readtemperature("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-temps-2.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-2.csv", tmp, yL[nD] );
  nD++;
  //
  readtemperature("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-temps-1.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-1.csv", tmp, yL[nD] );
  nD++;
  readtemperature("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-temps-2.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-2.csv", tmp, yL[nD] );
  nD++;
  //
  readtemperature("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-temps-1.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-1.csv", tmp, yL[nD] );
  nD++;
  readtemperature("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-temps-2.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-2.csv", tmp, yL[nD] );
  nD++;
  //
  readtemperature("20200826_HDR2-2e14/p10C/dark/HDR2-2e14-10C-dark-temps-1.csv",xD[nD],exD[nD]);
  readovervoltagefile("20200826_HDR2-2e14/p10C/dark/HDR2-2e14-10C-dark-1.csv", tmp, yL[nD] );
  nD++;
  //
  
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////

  
  gStyle->SetOptStat(0);

  TCanvas *main = new TCanvas();
  
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+24,100,36,41.5);
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
  
  TGraphErrors *grL = new TGraphErrors(nD, xD, yL, exD, eyL);
  grL->SetMarkerColor( kCyan-3 );
  grL->SetLineColor( kCyan-3 );
  grL->SetMarkerStyle( 20 );
  grL->Draw("PA");
  grL->Draw("PSAME");
  grL->Fit(fit1,"W");
  
  /*
  TGraphErrors *grLinearD = new TGraphErrors(nD, xD, yLinearMeanD, exD, yLinearStdD);
  grLinearD->SetMarkerColor( kGreen-3 );
  grLinearD->SetLineColor( kGreen-3 );
  grLinearD->SetMarkerStyle( 21 );
  grLinearD->Draw("PSAME");
  grLinearD->Fit(fit2,"W");

  TGraphErrors *grLandauL = new TGraphErrors(nL, xL, yLandauMeanL, exL, yLandauStdL);
  grLandauL->SetMarkerColor( kOrange-3 );
  grLandauL->SetLineColor( kOrange-3 );
  grLandauL->SetMarkerStyle( 22 );
  grLandauL->Draw("PSAME");
  grLandauL->Fit(fit3,"W");
  
  TGraphErrors *grLinearL = new TGraphErrors(nL, xL, yLinearMeanL, exL, yLinearStdL);
  grLinearL->SetMarkerColor( kRed-3 );
  grLinearL->SetLineColor( kRed-3 );
  grLinearL->SetMarkerStyle( 23 );
  grLinearL->Draw("PSAME");
  grLinearL->Fit(fit4,"W");

  double nx[1] = {23.5};
  double ny[1] = {38.4};
  double enx[1] = {0};
  double eny[1] = {0.1};
  TGraphErrors *nominal = new TGraphErrors(1,nx,ny,enx,eny);
  nominal->Draw("*SAME");
  
  TLegend *leg = new TLegend(0.51,0.16,0.84,0.35,"HDR2-2e14");
  leg->AddEntry(grLandauD,Form("DARK:: Max dLnI/dV: %.0f mV/deg",fit1->GetParameter(1)*1e3));
  leg->AddEntry(grLinearD,Form("DARK:: Xing sqrtI: %.0f mV/deg",fit2->GetParameter(1)*1e3));
  leg->AddEntry(grLandauL,Form("LED:: Max dLnI/dV: %.0f mV/deg",fit3->GetParameter(1)*1e3));
  leg->AddEntry(grLinearL,Form("LED:: Xing sqrtI: %.0f mV/deg",fit4->GetParameter(1)*1e3));
  leg->Draw();
  */
  
  main->SaveAs("outputfiles/20200826_HDR2-2e14/currentTrend.pdf","PDF");

  return 0;
}
