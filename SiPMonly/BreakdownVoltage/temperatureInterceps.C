#include "helpers.C"

int temperatureInterceps() {
  gStyle->SetOptStat(0);

  double x[8] = {0,0,1e13,5e13,2e14,1e13,2e14,5e13};
  double p0[8], p1[8];
  double s0[8], s1[8];

  readtemperaturetrendCoef("20200915_HDR2-1/temperatureTrend.txt",p0[0],p1[0],0);
  readtemperaturetrendCoef("20200916_HDR2-2/temperatureTrend.txt",p0[1],p1[1],0);
  readtemperaturetrendCoef("20200826_HDR2-1e13/temperatureTrend.txt",p0[2],p1[2],0);
  readtemperaturetrendCoef("20200826_HDR2-5e13/temperatureTrend.txt",p0[3],p1[3],0);
  readtemperaturetrendCoef("20200826_HDR2-2e14/temperatureTrend.txt",p0[4],p1[4],0);
  readtemperaturetrendCoef("20200915_HDR2-1e13-2/temperatureTrend.txt",p0[5],p1[5],0);
  readtemperaturetrendCoef("20200831_HDR2-2e14-2/temperatureTrend.txt",p0[6],p1[6],0);
  readtemperaturetrendCoef("20200831_HDR2-5e13-2/temperatureTrend.txt",p0[7],p1[7],0);

  readtemperaturetrendCoef("20200915_HDR2-1/temperatureTrend.txt",s0[0],s1[0],1);
  readtemperaturetrendCoef("20200916_HDR2-2/temperatureTrend.txt",s0[1],s1[1],1);
  readtemperaturetrendCoef("20200826_HDR2-1e13/temperatureTrend.txt",s0[2],s1[2],1);
  readtemperaturetrendCoef("20200826_HDR2-5e13/temperatureTrend.txt",s0[3],s1[3],1);
  readtemperaturetrendCoef("20200826_HDR2-2e14/temperatureTrend.txt",s0[4],s1[4],1);
  readtemperaturetrendCoef("20200915_HDR2-1e13-2/temperatureTrend.txt",s0[5],s1[5],1);
  readtemperaturetrendCoef("20200831_HDR2-2e14-2/temperatureTrend.txt",s0[6],s1[6],1);
  readtemperaturetrendCoef("20200831_HDR2-5e13-2/temperatureTrend.txt",s0[7],s1[7],1);
  
  for(int i=0; i!=8; ++i) {
    p1[i] *= 1e3;
    s1[i] *= 1e3;
    cout << "****PP " << p0[i] << " " << p1[i] << endl;
    cout << "****SS " << s0[i] << " " << s1[i] << endl;
  }
  
  /////////////
  // D O N E //
  /////////////

  ///////
  // display all
  TLine *lin = new TLine();
  lin->SetLineColor(kRed-3);
  TLatex *tex = new TLatex();

  TGraph *gr0P = new TGraph(8,x,p0);
  TGraph *gr1P = new TGraph(8,x,p1);
  TGraph *gr0S = new TGraph(8,x,s0);
  TGraph *gr1S = new TGraph(8,x,s1);
  TF1 *fit0P = new TF1("fit0P","[0]+[1]*x");
  TF1 *fit1P = new TF1("fit1P","[0]+[1]*x");
  TF1 *fit0S = new TF1("fit0S","[0]+[1]*x");
  TF1 *fit1S = new TF1("fit1S","[0]+[1]*x");
  fit0P->SetLineColor( kRed-3 );
  fit1P->SetLineColor( kRed-3 );
  fit0S->SetLineColor( kBlue-3 );
  fit1S->SetLineColor( kBlue-3 );
  
  gr0P->SetMarkerStyle(20);
  gr1P->SetMarkerStyle(20);
  gr0S->SetMarkerStyle(21);
  gr1S->SetMarkerStyle(21);
  gr0P->SetMarkerColor(kRed-3);
  gr1P->SetMarkerColor(kRed-3);
  gr0S->SetMarkerColor(kBlue-3);
  gr1S->SetMarkerColor(kBlue-3);
  gr0P->SetLineColor( kRed-3 );
  gr1P->SetLineColor( kRed-3 );
  gr0S->SetLineColor( kBlue-3 );
  gr1S->SetLineColor( kBlue-3 );
  
  TH2D *axis0 = new TH2D("axis0",";Fluence  #Phi^{1 MeV}_{N}  (cm^{-1});Intercept  @  0C  (V)", 100, 0, 2.2e14, 10000, 37, 41 );
  TH2D *axis1 = new TH2D("axis1",";Fluence  #Phi^{1 MeV}_{N}  (cm^{-1});Slope  (mV/deg)", 100, 0, 2.2e14, 10000, 25, 50 );

  TCanvas *main = new TCanvas("main","main",1600,600);
  main->Divide(2,1);
  main->cd(1);
  axis0->Draw("");
  gr0P->Draw("PSAME");
  gr0S->Draw("PSAME");
  gr0P->Fit(fit0P);
  gr0S->Fit(fit0S);
  //tex->DrawLatex(1e14,36.5,Form("%.1f  V  per  10^{14} #Phi",fit0P->GetParameter(1)*1e14));
  main->cd(2);
  axis1->Draw("");
  gr1P->Draw("PSAME");
  gr1S->Draw("PSAME");
  gr1P->Fit(fit1P);
  gr1S->Fit(fit1S);
  //tex->DrawLatex(1e14,36.5,Form("%.1f  mV/deg  per  10^{14} #Phi",fit1P->GetParameter(1)*1e14));

  TLegend *leg0 = new TLegend(0.45,0.15,0.85,0.3);
  leg0->AddEntry( fit0P, Form("%.2f  +  %.2f#times10^{-14} #Phi  (V)",fit0P->GetParameter(0),fit0P->GetParameter(1)*1e14) );
  leg0->AddEntry( fit0S, Form("%.2f  +  %.2f#times10^{-14} #Phi  (V)",fit0S->GetParameter(0),fit0S->GetParameter(1)*1e14) );
  main->cd(1);
  leg0->Draw();
  
  TLegend *leg1 = new TLegend(0.15,0.7,0.65,0.85);
  leg1->AddEntry( fit1P, Form("%.1f  +  %.1f#times10^{-14} #Phi  (mV/deg)",fit1P->GetParameter(0),1e14*fit1P->GetParameter(1)) );
  leg1->AddEntry( fit1S, Form("%.1f  +  %.1f#times10^{-14} #Phi  (mV/deg)",fit1S->GetParameter(0),1e14*fit1S->GetParameter(1)) );
  main->cd(2);
  leg1->Draw();

  cout << "Fluence || Intercept (V) || Slope (mV/deg)"   << endl;
  for(int i=0; i!=8; ++i) {
    cout << Form("%.1e || %5.2f | %5.2f || %5.2f | %5.2f", x[i], p0[i], p1[i], s0[i], s1[i]) << endl;
  }

  
  main->SaveAs( "HDR2_OverVoltage.pdf", "pdf" );

  return 0;
}
