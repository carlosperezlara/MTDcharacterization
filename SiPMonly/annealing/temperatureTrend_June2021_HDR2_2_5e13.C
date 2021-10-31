#include "helpers.C"

int temperatureTrend_June2021_HDR2_2_5e13() {  //loadTemperatureTables();
  double xP[100], exP[100];
  double yLandauMeanP[100];
  double yLandauStdP[100];
  double yLinearMeanP[100];
  double yLinearStdP[100];
  double tmp;

  //photon
  int nP=0;
  readtemperature_directly("input/MTD-5e13/humidity_MTD-SiPM-5e13-2-neg30C-light.csv.csv",xP[nP],exP[nP]);
  readfile("MTD-SiPM-5e13-2-neg30C-light.csv_MTD-SiPM-5e13-2-neg30C-dark.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  cout << "POINT " <<  yLandauMeanP[nP] << " " << yLinearMeanP[nP] << endl;
  nP++;
  //
  readtemperature_directly("input/MTD-5e13/humidity_MTD-SiPM-5e13-2-neg20C-light.csv.csv",xP[nP],exP[nP]);
  readfile("MTD-SiPM-5e13-2-neg20C-light.csv_MTD-SiPM-5e13-2-neg20C-dark.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  cout << "POINT " <<  yLandauMeanP[nP] << " "  << yLinearMeanP[nP] << endl;
  nP++;
  //
  //readtemperature_directly("input/MTD-5e13/humidity_MTD-SiPM-5e13-2-neg10C-light.csv.csv",xP[nP],exP[nP]);
  //readfile("MTD-SiPM-5e13-2-neg10C-light.csv_MTD-SiPM-5e13-2-neg10C-dark.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  //cout << "POINT " <<  yLandauMeanP[nP] << " "  << yLinearMeanP[nP] << endl;
  //nP++;
  //
  readtemperature_directly("input/MTD-5e13/humidity_MTD-SiPM-5e13-2-0C-light.csv.csv",xP[nP],exP[nP]);
  readfile("MTD-SiPM-5e13-2-0C-light.csv_MTD-SiPM-5e13-2-0C-dark.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  cout << "POINT " <<  yLandauMeanP[nP] << " "  << yLinearMeanP[nP] << endl;
  nP++;
  //
  readtemperature_directly("input/MTD-5e13/humidity_MTD-SiPM-5e13-2-5C-light.csv.csv",xP[nP],exP[nP]);
  readfile("MTD-SiPM-5e13-2-5C-light.csv_MTD-SiPM-5e13-2-5C-dark.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  cout << "POINT " <<  yLandauMeanP[nP] << " "  << yLinearMeanP[nP] << endl;
  nP++;
  //
  //readtemperature_directly("input/MTD-5e13/humidity_MTD-SiPM-5e13-2-22C-light.csv.csv",xP[nP],exP[nP]);
  //readfile("MTD-SiPM-5e13-2-22C-light.csv_MTD-SiPM-5e13-2-22C-dark.csv_IVCURVE.csv", yLandauMeanP[nP], yLandauStdP[nP], tmp, tmp, yLinearMeanP[nP], yLinearStdP[nP]);
  //cout << "POINT " <<  yLandauMeanP[nP] << " "  << yLinearMeanP[nP] << endl;
  //nP++;
  //
  
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////

  
  gStyle->SetOptStat(0);

  TCanvas *main = new TCanvas();
  
  TH2D *axis = new TH2D("axis",";Degrees;V_{br}",100,-34,+24,100,37.0,39.5);
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
  //nominal->Draw("*SAME");
  //nominal2->Draw("*SAME");
  
  TLegend *leg = new TLegend(0.51,0.16,0.84,0.35,"HDR2-2 new May2021");
  leg->AddEntry(grLandauP,Form("Max dLnI/dV: %.1f mV/deg",fit5->GetParameter(1)*1e3));
  leg->AddEntry(grLinearP,Form("Xing sqrtI: %.1f mV/deg",fit6->GetParameter(1)*1e3));
  //leg->AddEntry(nominal,"Manufacturer");
  leg->Draw();

  main->SaveAs("input/MTD-5e13/temperatureTrend.pdf","PDF");

  std::ofstream fou( "input/MTD-5e13/temperatureTrend.txt" );
  fou << Form("%e %e",fit5->GetParameter(0), fit5->GetParameter(1)) << std::endl;
  fou << Form("%e %e",fit6->GetParameter(0), fit6->GetParameter(1)) << std::endl;
  
  return 0;
}
