#include "helpers.C"

TF1 *gainenf;

void LoadGain() {
  TFile *rfile = new TFile("../../HDR2data/sipm_spec_input_HDR2-015-v2-1e13.root");
  rfile->ls();
  TF1 *gai = (TF1*) rfile->Get("fGain_vs_OV");
  cout << gai->GetFormula()->GetExpFormula() << endl;
  double p0G = gai->GetParameter(0);
  double p1G = gai->GetParameter(1);
  TF1 *enf = (TF1*) rfile->Get("fENF_vs_OV");
  double p0E = enf->GetParameter(0);
  double p1E = enf->GetParameter(1);
  gainenf = new TF1("gainenf",Form("(%f+x*%f)*(1+%f*x+%f*x*x)",p0G,p1G,p0E,p1E),0,10);
}

int dcr_HDR2_fluence_n30() {
  gStyle->SetOptStat(0);
  loadTemperatureTables();

  // load gain
  LoadGain();
  cout << gainenf->GetFormula()->GetExpFormula() << endl;

  const int NFILES=16;
  TString iFile[NFILES];
  TString tFile[NFILES];
  TString vbrFile[16];

  vbrFile[ 0] = "20200915_HDR2-1/temperatureTrend.txt";
  vbrFile[ 1] = "20200915_HDR2-1/temperatureTrend.txt";
  vbrFile[ 2] = "20200916_HDR2-2/temperatureTrend.txt";
  vbrFile[ 3] = "20200916_HDR2-2/temperatureTrend.txt";
  vbrFile[ 4] = "20200826_HDR2-1e13/temperatureTrend.txt";
  vbrFile[ 5] = "20200826_HDR2-1e13/temperatureTrend.txt";
  vbrFile[ 6] = "20200826_HDR2-1e13/temperatureTrend.txt";
  vbrFile[ 7] = "20200826_HDR2-1e13/temperatureTrend.txt";
  vbrFile[ 8] = "20200826_HDR2-5e13/temperatureTrend.txt";
  vbrFile[ 9] = "20200826_HDR2-5e13/temperatureTrend.txt";
  vbrFile[10] = "20200831_HDR2-5e13-2/temperatureTrend.txt";
  vbrFile[11] = "20200831_HDR2-5e13-2/temperatureTrend.txt";
  vbrFile[12] = "20200826_HDR2-2e14/temperatureTrend.txt";
  vbrFile[13] = "20200826_HDR2-2e14/temperatureTrend.txt";
  vbrFile[14] = "20200831_HDR2-2e14-2/temperatureTrend.txt";
  vbrFile[15] = "20200831_HDR2-2e14-2/temperatureTrend.txt";
  //===
  iFile[ 0] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-1.csv";
  iFile[ 1] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-2.csv";
  iFile[ 2] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-1.csv";
  iFile[ 3] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-2.csv";
  iFile[ 4] = "20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-1.csv";
  iFile[ 5] = "20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-2.csv";
  iFile[ 6] = "20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-1.csv";
  iFile[ 7] = "20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-2.csv";
  iFile[ 8] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-1.csv";
  iFile[ 9] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-2.csv";
  iFile[10] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-1.csv";
  iFile[11] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-2.csv";
  iFile[12] = "20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-1.csv";
  iFile[13] = "20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-2.csv";
  iFile[14] = "20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-1.csv";
  iFile[15] = "20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-2.csv";
  //===
  tFile[ 0] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-temps-1.csv";
  tFile[ 1] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-temps-2.csv";
  tFile[ 2] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-temps-1.csv";
  tFile[ 3] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-temps-1.csv";
  tFile[ 4] = "20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-1-temps.csv";
  tFile[ 5] = "20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-2-temps.csv";
  tFile[ 6] = "20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-temps-1.csv";
  tFile[ 7] = "20200915_HDR2-1e13-2/n30C/dark/HDR2-1e13-2-n30C-dark-temps-2.csv";
  tFile[ 8] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-1.csv";
  tFile[ 9] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-2.csv";
  tFile[10] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-1.csv";
  tFile[11] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-2.csv";  
  tFile[12] = "20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv";
  tFile[13] = "20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-2.csv";
  tFile[14] = "20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-temps-1.csv";
  tFile[15] = "20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-temps-2.csv";

  int col[8] = { kMagenta-3, kRed-3, kOrange-3, kGreen-3, kCyan-3, kBlue-3, kGray+1, kBlack };
  
  double volt[NFILES][MAX];
  double curr[NFILES][MAX];
  int n[NFILES];
  double tempStd[NFILES], tempMea[NFILES];
  double vbr[NFILES];
  double voltD[NFILES][MAX];
  double currN[NFILES][MAX];
  TGraph *grIV[NFILES];
  TGraph *grDCR[NFILES];
  TGraph *grDCRscaled[NFILES];
  TSpline *spDCR[NFILES];
  for(int i=0; i!=NFILES; ++i) {
    // read ivcurves
    n[i] = readfile( iFile[i], volt[i], curr[i] );
    // read temperatures
    readtemperature( tFile[i], tempMea[i], tempStd[i] );
    vbr[i] = readtemperaturetrend(vbrFile[i], tempMea[i], 0);
    cout << "* Breakdown voltage " << vbr[i] << " at " << tempMea[i] << "C "<< endl;
    // scale DCR
    for(int j=0; j!=n[i]; ++j) {
      voltD[i][j] = volt[i][j] - vbr[i];
    }
    grIV[i]  = new TGraph( n[i], volt[i],  curr[i] );
    if(i<12) {
      grIV[i]->SetMarkerStyle(24);
    } else {
      grIV[i]->SetMarkerStyle(25);
    }
    grIV[i]->SetMarkerColor( col[i/2] );
    grIV[i]->SetLineWidth(0);
  }

  TCanvas *main = new TCanvas();
  double xxx[16] = {1,1,1,1,
    1e13,1e13,1e13,1e13,
    5e13,5e13,5e13,5e13,
    2e14,2e14,2e14,2e14
  };
  TH2D *axis1 = new TH2D("axis1",";Bias  Voltage  (V);Current  (A)",100,0,45,100,1e-12,1e-1);
  main->SetLogy(1);
  TF1 *fitLeak[NFILES];
  axis1->Draw();
  for(int i=0; i!=NFILES; ++i) {
    fitLeak[i] = new TF1( Form("leakFit%d",i), "expo", -10, 80 );
    fitLeak[i]->SetLineColor( col[i/2] );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Draw("PSAME");
    for(int j=0; j!=n[i]; ++j) {
      currN[i][j] = (curr[i][j]-fitLeak[i]->Eval(volt[i][j]))/(1.6e-19)/gainenf->Eval( voltD[i][j] ) *1e-9;
    }
    grDCR[i] = new TGraph( n[i], voltD[i], currN[i] );
    for(int j=0; j!=n[i]; ++j) {
      currN[i][j] = currN[i][j]*1e+9/xxx[i];
    }
    grDCRscaled[i] = new TGraph( n[i], voltD[i], currN[i] );
    if(i%2==0) {
      grDCR[i]->SetMarkerStyle(24);
      grDCRscaled[i]->SetMarkerStyle(24);
    } else {
      grDCR[i]->SetMarkerStyle(25);
      grDCRscaled[i]->SetMarkerStyle(25);
    }
    grDCR[i]->SetMarkerColor( col[i/2] );
    grDCR[i]->SetLineWidth(0);
    grDCRscaled[i]->SetMarkerColor( col[i/2] );
    grDCRscaled[i]->SetLineWidth(0);
    spDCR[i] = new TSpline3( Form("sp%d",i), grDCR[i]);
  }

  TCanvas *main2 = new TCanvas();
  main2->SetLogy(1);
  main2->SetGridx(1);
  main2->SetGridy(1);
  TH2D *axis2 = new TH2D("axis2",";Overvoltage  (V);Dark Count Rate  (I^{sub}/e/gain/enf*1e-9)    (GHz)",100,0,7,100,1e-7,1e3);
  axis2->Draw();
  for(int i=0; i!=NFILES; ++i)
    grDCR[i]->Draw("SAMEP");

  TString legs[16] = {
    "NonI","NonI","NonI","NonI",
    "1e13","1e13","1e13","1e13",
    "5e13","5e13","5e13","5e13",
    "2e13","2e14","2e14","2e14" };
  TLegend *leg = new TLegend(0.53,0.63,0.88,0.87,"HDR2      @ -30 C");
  for(int i=0; i!=NFILES; ++i) {
    leg->AddEntry( grDCR[i], legs[i].Data() );
  }
  leg->SetNColumns(4);
  leg->Draw();
  //main2->SaveAs("DCR_HDR2.pdf","pdf");
  main->cd()->SetLogy(1);
  //leg1->Draw();

  TCanvas *main2scaled = new TCanvas();
  main2scaled->SetLogy(1);
  main2scaled->SetGridx(1);
  main2scaled->SetGridy(1);
  TH2D *axis2scaled = new TH2D("axis2",";Overvoltage  (V);Dark Count Rate Over Fluence  (I^{sub}/e/gain/enf)/#Phi    (Hz)",100,0,7,100,1e-5,1e-2);
  axis2scaled->Draw();
  for(int i=0; i!=NFILES; ++i)
    grDCRscaled[i]->Draw("PSAME");
  
  TCanvas *main3 = new TCanvas();
  //main3->SetLogy(1);
  double yT[4][NFILES];
  cout << "Fluence|| DCR (GHz)" << endl;
  for(int i=0; i!=NFILES; ++i) {
    yT[0][i] = spDCR[i]->Eval(0.8);
    cout << Form(" %.0e || %.2e\n",xxx[i], yT[0][i]);
  }
  TH2D *axis3 = new TH2D("axis3",";#Phi;Dark Count Rate   (GHz)",100,0,2.1e14,100,0,180);
  axis3->Draw();
  TGraph *grT[4];
  int colorT[4] = {kBlack, kGray, kGray+1, kYellow-3 };
  for(int i=0; i!=1; ++i) {
    grT[i] = new TGraph(NFILES,xxx,yT[i]);
    grT[i]->SetMarkerColor( colorT[i]  );
    grT[i]->SetLineWidth(0);
    grT[i]->SetMarkerStyle(20);
    grT[i]->Draw("PSAME");
  }
  //TF1 *fitT = new TF1("fitT","[0]+[1]*x");
  //grT[0]->Fit(fitT);
  //grT[0]->Fit(fitT);
  
  TLegend *legT = new TLegend(0.14,0.69,0.54,0.87,"HDR2      @ -30C");
  legT->AddEntry(grT[0],"DCR @ OV=0.8");
  //legT->AddEntry(fitT,Form("%.1f + %.1f#times10^{-14} #Phi",fitT->GetParameter(0),fitT->GetParameter(1)*1E14) );
  legT->Draw();
  return 0;

}
