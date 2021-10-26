#include "helpers.C"

int temperatureTrendHDR2_1() {
  loadTemperatureTables();
  double xD[100], exD[100];
  double xL[100], exL[100];
  double xP[100], exP[100];
  double yLandauMeanP[100];
  double yLandauStdP[100];
  double yLinearMeanP[100];
  double yLinearStdP[100];
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
  readtemperature("20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;

  
  //light
  int nL=0;
  readtemperature("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-257nA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-257nA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-257nA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-257nA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-257nA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-257nA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-257nA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-257nA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-257nA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-257nA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-257nA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-257nA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //


  //photon
  int nP=0;
  readtemperature("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-257nA-Orange-1.csv_HDR2-0e0-1-n30C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-257nA-Orange-2.csv_HDR2-0e0-1-n30C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-257nA-Orange-1.csv_HDR2-0e0-1-n20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/n20C/light/HDR2-0e0-1-n20C-257nA-Orange-2.csv_HDR2-0e0-1-n20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-257nA-Orange-1.csv_HDR2-0e0-1-n10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/n10C/light/HDR2-0e0-1-n10C-257nA-Orange-2.csv_HDR2-0e0-1-n10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-257nA-Orange-1.csv_HDR2-0e0-1-0C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/zeroC/light/HDR2-0e0-1-0C-257nA-Orange-2.csv_HDR2-0e0-1-0C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-257nA-Orange-1.csv_HDR2-0e0-1-10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/p10C/light/HDR2-0e0-1-10C-257nA-Orange-2.csv_HDR2-0e0-1-10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-257nA-Orange-1.csv_HDR2-0e0-1-20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1/p20C/light/HDR2-0e0-1-20C-257nA-Orange-2.csv_HDR2-0e0-1-20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////

  
  gStyle->SetOptStat(0);

  TCanvas *main = new TCanvas();
  
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+24,100,36,39.0);
  axis->GetYaxis()->SetNdivisions(509);
  axis->Draw();
  
  TF1 *fit1 = new TF1("fit1","[0]+[1]*x");
  TF1 *fit2 = new TF1("fit2","[0]+[1]*x");  
  TF1 *fit3 = new TF1("fit3","[0]+[1]*x");  
  TF1 *fit4 = new TF1("fit4","[0]+[1]*x");  
  TF1 *fit5 = new TF1("fit5","[0]+[1]*x");  
  TF1 *fit6 = new TF1("fit6","[0]+[1]*x");  
  fit1->SetLineColor(kCyan-3);
  fit2->SetLineColor(kGreen-3);
  fit3->SetLineColor(kOrange-3);
  fit4->SetLineColor(kRed-3);
  fit5->SetLineColor(kRed-3);
  fit6->SetLineColor(kBlue-3);
  
  TGraphErrors *grLandauD = new TGraphErrors(nD, xD, yLandauMeanD, exD, yLandauStdD);
  grLandauD->SetMarkerColor( kCyan-3 );
  grLandauD->SetLineColor( kCyan-3 );
  grLandauD->SetMarkerStyle( 20 );
  //grLandauD->Draw("PSAME");
  //grLandauD->Fit(fit1,"W");
  
  TGraphErrors *grLinearD = new TGraphErrors(nD, xD, yLinearMeanD, exD, yLinearStdD);
  grLinearD->SetMarkerColor( kGreen-3 );
  grLinearD->SetLineColor( kGreen-3 );
  grLinearD->SetMarkerStyle( 21 );
  //grLinearD->Draw("PSAME");
  //grLinearD->Fit(fit2,"W");

  
  TGraphErrors *grLandauL = new TGraphErrors(nL, xL, yLandauMeanL, exL, yLandauStdL);
  grLandauL->SetMarkerColor( kOrange-3 );
  grLandauL->SetLineColor( kOrange-3 );
  grLandauL->SetMarkerStyle( 22 );
  //grLandauL->Draw("PSAME");
  //grLandauL->Fit(fit3,"W");
  
  TGraphErrors *grLinearL = new TGraphErrors(nL, xL, yLinearMeanL, exL, yLinearStdL);
  grLinearL->SetMarkerColor( kRed-3 );
  grLinearL->SetLineColor( kRed-3 );
  grLinearL->SetMarkerStyle( 23 );
  //grLinearL->Draw("PSAME");
  //grLinearL->Fit(fit4,"W");

  TGraphErrors *grLandauP = new TGraphErrors(nP, xP, yLandauMeanP, exP, yLandauStdP);
  grLandauP->SetMarkerColor( kRed-3 );
  grLandauP->SetLineColor( kRed-3 );
  grLandauP->SetMarkerStyle( 22 );
  grLandauP->Draw("PSAME");
  grLandauP->Fit(fit5,"W");
  
  TGraphErrors *grLinearP = new TGraphErrors(nP, xP, yLinearMeanP, exP, yLinearStdP);
  grLinearP->SetMarkerColor( kBlue-3 );
  grLinearP->SetLineColor( kBlue-3 );
  grLinearP->SetMarkerStyle( 23 );
  grLinearP->Draw("PSAME");
  grLinearP->Fit(fit6,"W");
  
  double nx[1] = {23.5};
  double ny[1] = {38.3};
  double ny2[1] = {38.5};
  TGraph *nominal = new TGraph(1,nx,ny);
  TGraph *nominal2 = new TGraph(1,nx,ny2);
  nominal->Draw("*SAME");
  //nominal2->Draw("*SAME");
  
  TLegend *leg = new TLegend(0.51,0.16,0.84,0.35,"HDR2-1");
  //leg->AddEntry(grLandauD,Form("DARK:: Max dLnI/dV: %.0f mV/deg",fit1->GetParameter(1)*1e3));
  //leg->AddEntry(grLinearD,Form("DARK:: Xing sqrtI: %.0f mV/deg",fit2->GetParameter(1)*1e3));
  //leg->AddEntry(grLandauL,Form("LED:: Max dLnI/dV: %.0f mV/deg",fit3->GetParameter(1)*1e3));
  //leg->AddEntry(grLinearL,Form("LED:: Xing sqrtI: %.0f mV/deg  [%.1f mV/deg^{2}]",fit4->GetParameter(1)*1e3,
  //			       fit4->GetParameter(2)*1e3));
  leg->AddEntry(grLandauP,Form("Max dLnI/dV: %.1f mV/deg",fit5->GetParameter(1)*1e3));
  leg->AddEntry(grLinearP,Form("Xing sqrtI: %.1f mV/deg",fit6->GetParameter(1)*1e3));
  leg->AddEntry(nominal,"Manufacturer");
  leg->Draw();

  main->SaveAs("outputfiles/20200915_HDR2-1/temperatureTrend.pdf","PDF");

  std::ofstream fou( "outputfiles/20200915_HDR2-1/temperatureTrend.txt" );
  fou << Form("%e %e",fit5->GetParameter(0), fit5->GetParameter(1)) << std::endl;
  fou << Form("%e %e",fit6->GetParameter(0), fit6->GetParameter(1)) << std::endl;
  
  return 0;
}
