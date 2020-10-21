#include "helpers.C"

int temperatureTrendHDR1e13_2() {
  loadTemperatureTables();
  double xD[100], exD[100];
  double xL[100], exL[100];
  double xP[100], exP[100];
  double yLandauMeanL[100];
  double yLandauStdL[100];
  double yLinearMeanL[100];
  double yLinearStdL[100];
  double yLandauMeanD[100];
  double yLandauStdD[100];
  double yLinearMeanD[100];
  double yLinearStdD[100];
  double yLandauMeanP[100];
  double yLandauStdP[100];
  double yLinearMeanP[100];
  double yLinearStdP[100];
  double tmp;


  //dark
  int nD=0;
  readtemperature("20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1e13-2/n20C/dark/HDR2-1e13-2-n20C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/n20C/dark/HDR2-1e13-2-n20C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1e13-2/n20C/dark/HDR2-1e13-2-n20C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/n20C/dark/HDR2-1e13-2-n20C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1e13-2/n10C/dark/HDR2-1e13-2-n10C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/n10C/dark/HDR2-1e13-2-n10C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1e13-2/n10C/dark/HDR2-1e13-2-n10C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/n10C/dark/HDR2-1e13-2-n10C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1e13-2/zeroC/dark/HDR2-1e13-2-0C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/zeroC/dark/HDR2-1e13-2-0C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1e13-2/zeroC/dark/HDR2-1e13-2-0C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/zeroC/dark/HDR2-1e13-2-0C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1e13-2/p10C/dark/HDR2-1e13-2-10C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/p10C/dark/HDR2-1e13-2-10C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1e13-2/p10C/dark/HDR2-1e13-2-10C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/p10C/dark/HDR2-1e13-2-10C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  //
  readtemperature("20200915_HDR2-1e13-2/p20C/dark/HDR2-1e13-2-20C-dark-temps-1.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/p20C/dark/HDR2-1e13-2-20C-dark-1.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
  readtemperature("20200915_HDR2-1e13-2/p20C/dark/HDR2-1e13-2-20C-dark-temps-2.csv",xD[nD],exD[nD]);
  readfile("20200915_HDR2-1e13-2/p20C/dark/HDR2-1e13-2-20C-dark-2.csv", yLandauMeanD[nD], yLandauStdD[nD], tmp, tmp, yLinearMeanD[nD], yLinearStdD[nD]);
  nD++;
    
  //photons
  int nP=0;
  readtemperature("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-5.9mA-Orange-1.csv_HDR2-1e13-2-n30C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-5.9mA-Orange-2.csv_HDR2-1e13-2-n30C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-6.35mA-Orange-1.csv_HDR2-1e13-2-n20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-6.35mA-Orange-2.csv_HDR2-1e13-2-n20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-6.35mA-Orange-1.csv_HDR2-1e13-2-n10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-6.35mA-Orange-2.csv_HDR2-1e13-2-n10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-7.5mA-Orange-1.csv_HDR2-1e13-2-0C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-7.5mA-Orange-2.csv_HDR2-1e13-2-0C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-8.4mA-Orange-1.csv_HDR2-1e13-2-10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-8.4mA-Orange-2.csv_HDR2-1e13-2-10C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  readtemperature("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-light-temps-1.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-9.1mA-Orange-1.csv_HDR2-1e13-2-20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  readtemperature("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-light-temps-2.csv",xP[nP],exP[nP]);
  readfile("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-9.1mA-Orange-2.csv_HDR2-1e13-2-20C-dark-1.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  nP++;
  //
  
  //light
  int nL=0;
  readtemperature("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-5.9mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/n30C/light/HDR2-1e13-2-n30C-5.9mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-6.35mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/n20C/light/HDR2-1e13-2-n20C-6.35mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-6.35mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/n10C/light/HDR2-1e13-2-n10C-6.35mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-7.5mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/zeroC/light/HDR2-1e13-2-0C-7.5mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-8.4mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/p10C/light/HDR2-1e13-2-10C-8.4mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  readtemperature("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-light-temps-1.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-9.1mA-Orange-1.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  readtemperature("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-light-temps-2.csv",xL[nL],exL[nL]);
  readfile("20200915_HDR2-1e13-2/p20C/light/HDR2-1e13-2-20C-9.1mA-Orange-2.csv", yLandauMeanL[nL], yLandauStdL[nL], tmp, tmp, yLinearMeanL[nL], yLinearStdL[nL]);
  nL++;
  //
  
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////

  TCanvas *main = new TCanvas();
  
  gStyle->SetOptStat(0);
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+24,100,36.5,39);
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
  //grLandauD->Fit(fit1,"WW");
  
  TGraphErrors *grLinearD = new TGraphErrors(nD, xD, yLinearMeanD, exD, yLinearStdD);
  grLinearD->SetMarkerColor( kGreen-3 );
  grLinearD->SetLineColor( kGreen-3 );
  grLinearD->SetMarkerStyle( 21 );
  //grLinearD->Draw("PSAME");
  //grLinearD->Fit(fit2,"WW");

  TGraphErrors *grLandauL = new TGraphErrors(nL, xL, yLandauMeanL, exL, yLandauStdL);
  grLandauL->SetMarkerColor( kOrange-3 );
  grLandauL->SetLineColor( kOrange-3 );
  grLandauL->SetMarkerStyle( 22 );
  //grLandauL->Draw("PSAME");
  //grLandauL->Fit(fit3,"WW");
  
  TGraphErrors *grLinearL = new TGraphErrors(nL, xL, yLinearMeanL, exL, yLinearStdL);
  grLinearL->SetMarkerColor( kRed-3 );
  grLinearL->SetLineColor( kRed-3 );
  grLinearL->SetMarkerStyle( 23 );
  //grLinearL->Draw("PSAME");
  //grLinearL->Fit(fit4,"WW");

  TGraphErrors *grLandauP = new TGraphErrors(nP, xP, yLandauMeanP, exP, yLandauStdP);
  grLandauP->SetMarkerColor( kRed-3 );
  grLandauP->SetLineColor( kRed-3 );
  grLandauP->SetMarkerStyle( 22 );
  grLandauP->Draw("PSAME");
  grLandauP->Fit(fit5,"WW");
  
  TGraphErrors *grLinearP = new TGraphErrors(nP, xP, yLinearMeanP, exP, yLinearStdP);
  grLinearP->SetMarkerColor( kBlue-3 );
  grLinearP->SetLineColor( kBlue-3 );
  grLinearP->SetMarkerStyle( 23 );
  grLinearP->Draw("PSAME");
  grLinearP->Fit(fit6,"WW");

  double nx[1] = {23.5};
  double ny[1] = {38.4};
  double enx[1] = {0};
  double eny[1] = {0.1};
  TGraphErrors *nominal = new TGraphErrors(1,nx,ny,enx,eny);
  //nominal->Draw("*SAME");
  
  TLegend *leg = new TLegend(0.51,0.16,0.84,0.35,"HDR2-1e13-2");
  //leg->AddEntry(grLandauD,Form("DARK:: Max dLnI/dV: %.0f mV/deg",fit1->GetParameter(1)*1e3));
  //leg->AddEntry(grLinearD,Form("DARK:: Xing sqrtI: %.0f mV/deg",fit2->GetParameter(1)*1e3));
  //leg->AddEntry(grLandauL,Form("LED:: Max dLnI/dV: %.0f mV/deg",fit3->GetParameter(1)*1e3));
  //leg->AddEntry(grLinearL,Form("LED:: Xing sqrtI: %.0f mV/deg",fit4->GetParameter(1)*1e3));
  leg->AddEntry(grLandauP,Form("Max dLnI/dV: %.1f mV/deg",fit5->GetParameter(1)*1e3));
  leg->AddEntry(grLinearP,Form("Xing sqrtI: %.1f mV/deg",fit6->GetParameter(1)*1e3));
  leg->Draw();

  cout << "Temp  || Method A      | Method B"   << endl;
  for(int i=0; i!=nP; ++i) {
    cout << Form("%+5.1f || %5.2f +- %.2f | %5.2f +- %.2f", xP[i], yLandauMeanP[i], yLandauStdP[i], yLinearMeanP[i], yLinearStdP[i]) << endl;
  }
  main->SaveAs("outputfiles/20200915_HDR2-1e13-2/temperatureTrend.pdf","PDF");

  std::ofstream fou( "outputfiles/20200915_HDR2-1e13-2/temperatureTrend.txt" );
  fou << Form("%e %e",fit5->GetParameter(0), fit5->GetParameter(1)) << std::endl;
  fou << Form("%e %e",fit6->GetParameter(0), fit6->GetParameter(1)) << std::endl;

  return 0;
}
