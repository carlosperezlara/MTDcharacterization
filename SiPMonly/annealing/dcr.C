#include "helpers.C"

TF1 *gain;

void LoadGain() {
  TFile *rfile = new TFile("../../HDR2data/sipm_spec_input_HDR2-015-v2-1e13.root");
  rfile->ls();
  TF1 *gai = (TF1*) rfile->Get("fGain_vs_OV");
  cout << gai->GetFormula()->GetExpFormula() << endl;
  double p0G = gai->GetParameter(0);
  double p1G = gai->GetParameter(1);
  gain = new TF1("gain",Form("%f+x*%f",p0G,p1G),0,10);
}

int dcr(TString file="20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-1.csv",
	TString filetemp="20200915_HDR2-1/temperatureTrend.txt",
	TString filetempX="20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv" ) {
  gStyle->SetOptStat(0);

  
  
  // read ivcurve
  double volt[MAX];
  double curr[MAX];
  int n = readfile( file, volt, curr );
  // read temperatures
  loadTemperatureTables();
  double temperatureStd, temperatureMea;
  readtemperature(filetempX, temperatureMea, temperatureStd);
  cout << "* "<< temperatureMea << endl;
  // read bvoltage from trend
  double  bvoltage = readtemperaturetrend(filetemp, temperatureMea,0);
  cout << "* "<< bvoltage << endl;
  // load gain
  LoadGain();
  cout << gain->GetFormula()->GetExpFormula() << endl;
  

  double voltD[MAX];
  double currN[MAX];
  for(int i=0; i!=n; ++i) {
    voltD[i] = volt[i] - bvoltage;
    currN[i] = curr[i]/(1.6e-19)/gain->Eval( voltD[i] );
  }
  // create graphical objects
  TGraph  *gr0 = new TGraph(n,volt,curr);
  TSpline *sp0 = new TSpline3("sp0",gr0);
  TGraph  *gr1 = new TGraph(n,voltD,currN);
  TSpline *sp1 = new TSpline3("sp1",gr1);

  /*
  double overV[100];
  int nov;
  for(nov=0; nov!=100; ++nov) {
    overV[nov] = bvoltage + nov*0.1;
    if(overV[nov] > volt[n-1]) break;
  }
  */
  
  /////////////
  // D O N E //
  /////////////

  ///////
  // display all
  //double min0 = bvoltage - 1;
  //double max0 = overV[nov-1] + 1;

  TLine *lin = new TLine();
  lin->SetLineColor(kRed-3);
  TLatex *tex = new TLatex();

  TCanvas *main = new TCanvas();
  gr0->Draw("*A");
  gr0->GetXaxis()->SetTitle("Bias  Voltage   (V)");
  gr0->GetYaxis()->SetTitle("Current   (A)");
  gr0->SetMarkerColor(kGreen-3);
  sp0->Draw("SAME");

  TCanvas *main2 = new TCanvas();
  TH2D *axis1 = new TH2D("axis1",";Overvoltage  (V);Dark Count Rate  (I/e/gain)",100,0.6,7,100,0,1e11);
  axis1->Draw();
  gr1->Draw("*SAME");
  //gr1->Draw("*A");
  gr1->SetMarkerColor(kGreen-3);
  //sp1->Draw("SAME");
  //gain->Draw("SAME");
  
  //tex->SetTextSize(0.03);
  //tex->DrawTextNDC(0.12,0.85,Form("%s",file.Data()));
  //tex->SetTextSize(0.05);
  /*
  for(int i=0; i!=nov; ++i) {
    cout << "===> " << overV[i] << endl;
    //lin->DrawLine( overV[i], 0, overV[i], 1e6 );
    lin->DrawLine( overV[i], 0, overV[i], 1 );
  }
  main->SaveAs( Form("%s_OverVoltage.pdf",outfilestring.Data()), "pdf" );

  // Saving data
  ofstream fout( Form("%s_OverVoltage.txt",outfilestring.Data()) );
  fout << file.Data() << " " << std::endl;
  for(int i=0; i!=nov; ++i) {
    fout << overV[i] << " " << sp0->Eval( overV[i] ) << std::endl;
  }
  fout.close();
  */  
  return 0;
}
