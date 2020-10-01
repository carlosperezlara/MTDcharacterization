#include "helpers.C"

int temperatureInterceps(TString file="20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-1.csv",
			 TString filetemp="20200826_HDR2-2e14/temperatureTrend.txt",
			 TString filetempX="20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv" ) {
  gStyle->SetOptStat(0);

  double x[8] = {1,1,1e13,5e13,2e14,1e13,2e14,5e13};
  double p0[8], p1[8];
  readtemperaturetrendCoef("20200915_HDR2-1/temperatureTrend.txt",p0[0],p1[0]);
  readtemperaturetrendCoef("20200815_HDR2-2/temperatureTrend.txt",p0[1],p1[1]);
  readtemperaturetrendCoef("20200826_HDR2-1e13/temperatureTrend.txt",p0[2],p1[2]);
  readtemperaturetrendCoef("20200826_HDR2-5e13/temperatureTrend.txt",p0[3],p1[3]);
  readtemperaturetrendCoef("20200826_HDR2-2e14/temperatureTrend.txt",p0[4],p1[4]);
  readtemperaturetrendCoef("20200915_HDR2-1e13-2/temperatureTrend.txt",p0[5],p1[5]);
  readtemperaturetrendCoef("20200831_HDR2-2e14-2/temperatureTrend.txt",p0[6],p1[6]);
  readtemperaturetrendCoef("20200831_HDR2-5e13-2/temperatureTrend.txt",p0[7],p1[7]);

  for(int i=0; i!=8; ++i)
    p1[i] *= 1e3;
  
  /////////////
  // D O N E //
  /////////////

  ///////
  // display all
  TLine *lin = new TLine();
  lin->SetLineColor(kRed-3);
  TLatex *tex = new TLatex();

  TGraph *gr0 = new TGraph(8,x,p0);
  TGraph *gr1 = new TGraph(8,x,p1);
  gr0->SetMarkerStyle(20);
  gr0->SetMarkerColor(kBlack);
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerColor(kBlack);
  
  TH2D *axis0 = new TH2D("axis0",";Rad;p0  (V)", 100, 0.1, 2.2e14, 10000, 36, 42 );
  TH2D *axis1 = new TH2D("axis1",";Rad;p1  (mV/deg)", 100, 0.1, 2.2e14, 10000, 0, 50 );
  TF1 *fit0 = new TF1("fit0","[0]+[1]*x");
  TF1 *fit1 = new TF1("fit1","[0]");

  TCanvas *main = new TCanvas("main","main",1600,600);
  main->Divide(2,1);
  main->cd(1);
  axis0->Draw("");
  gr0->Draw("PSAME");
  gr0->Fit(fit0);
  tex->DrawLatex(1e14,36.5,Form("%.1f  mV / 10^{12} Rad",fit0->GetParameter(1)*1e3*1e12));
  main->cd(2);
  axis1->Draw("");
  gr1->Draw("PSAME");
  gr1->Fit(fit1);

  //main->SaveAs( Form("%s_OverVoltage.pdf",outfilestring.Data()), "pdf" );

  return 0;
}
