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

int dcr_HDR2() {
  gStyle->SetOptStat(0);
  loadTemperatureTables();

  // read bvoltage from trend
  //TString filetemp="20200915_HDR2-1/temperatureTrend.txt";
  TString filetemp="20200916_HDR2-2/temperatureTrend.txt";
  // load gain
  LoadGain();
  cout << gainenf->GetFormula()->GetExpFormula() << endl;

  const int NFILES=24;
  TString iFile[NFILES];
  TString tFile[NFILES];
  TString vbrFile[2] = {"20200915_HDR2-1/temperatureTrend.txt",
    "20200916_HDR2-2/temperatureTrend.txt"};
  
  iFile[ 0] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-1.csv";
  iFile[ 1] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-2.csv";
  iFile[ 2] = "20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-1.csv";
  iFile[ 3] = "20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-2.csv";
  iFile[ 4] = "20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-1.csv";
  iFile[ 5] = "20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-2.csv";
  iFile[ 6] = "20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-1.csv";
  iFile[ 7] = "20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-2.csv";
  iFile[ 8] = "20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-1.csv";
  iFile[ 9] = "20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-2.csv";
  iFile[10] = "20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-1.csv";
  iFile[11] = "20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-2.csv";
  tFile[ 0] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-temps-1.csv";
  tFile[ 1] = "20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-temps-2.csv";
  tFile[ 2] = "20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-temps-1.csv";
  tFile[ 3] = "20200915_HDR2-1/n20C/dark/HDR2-0e0-1-n20C-dark-temps-2.csv";
  tFile[ 4] = "20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-temps-1.csv";
  tFile[ 5] = "20200915_HDR2-1/n10C/dark/HDR2-0e0-1-n10C-dark-temps-2.csv";
  tFile[ 6] = "20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-temps-1.csv";
  tFile[ 7] = "20200915_HDR2-1/zeroC/dark/HDR2-0e0-1-0C-dark-temps-2.csv";
  tFile[ 8] = "20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-temps-1.csv";
  tFile[ 9] = "20200915_HDR2-1/p10C/dark/HDR2-0e0-1-10C-dark-temps-2.csv";
  tFile[10] = "20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-temps-1.csv";
  tFile[11] = "20200915_HDR2-1/p20C/dark/HDR2-0e0-1-20C-dark-temps-2.csv";

  iFile[12] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-1.csv";
  iFile[13] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-2.csv";
  iFile[14] = "20200916_HDR2-2/n20C/dark/HDR2-0e0-2-n20C-dark-1.csv";
  iFile[15] = "20200916_HDR2-2/n20C/dark/HDR2-0e0-2-n20C-dark-2.csv";
  iFile[16] = "20200916_HDR2-2/n10C/dark/HDR2-0e0-2-n10C-dark-1.csv";
  iFile[17] = "20200916_HDR2-2/n10C/dark/HDR2-0e0-2-n10C-dark-2.csv";
  iFile[18] = "20200916_HDR2-2/zeroC/dark/HDR2-0e0-2-0C-dark-1.csv";
  iFile[19] = "20200916_HDR2-2/zeroC/dark/HDR2-0e0-2-0C-dark-2.csv";
  iFile[20] = "20200916_HDR2-2/p10C/dark/HDR2-0e0-2-10C-dark-1.csv";
  iFile[21] = "20200916_HDR2-2/p10C/dark/HDR2-0e0-2-10C-dark-2.csv";
  iFile[22] = "20200916_HDR2-2/p20C/dark/HDR2-0e0-2-20C-dark-1.csv";
  iFile[23] = "20200916_HDR2-2/p20C/dark/HDR2-0e0-2-20C-dark-2.csv";
  tFile[12] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-temps-1.csv";
  tFile[13] = "20200916_HDR2-2/n30C/dark/HDR2-0e0-2-n30C-dark-temps-2.csv";
  tFile[14] = "20200916_HDR2-2/n20C/dark/HDR2-0e0-2-n20C-dark-temps-1.csv";
  tFile[15] = "20200916_HDR2-2/n20C/dark/HDR2-0e0-2-n20C-dark-temps-2.csv";
  tFile[16] = "20200916_HDR2-2/n10C/dark/HDR2-0e0-2-n10C-dark-temps-1.csv";
  tFile[17] = "20200916_HDR2-2/n10C/dark/HDR2-0e0-2-n10C-dark-temps-2.csv";
  tFile[18] = "20200916_HDR2-2/zeroC/dark/HDR2-0e0-2-0C-dark-temps-1.csv";
  tFile[19] = "20200916_HDR2-2/zeroC/dark/HDR2-0e0-2-0C-dark-temps-2.csv";
  tFile[20] = "20200916_HDR2-2/p10C/dark/HDR2-0e0-2-10C-dark-temps-1.csv";
  tFile[21] = "20200916_HDR2-2/p10C/dark/HDR2-0e0-2-10C-dark-temps-2.csv";
  tFile[22] = "20200916_HDR2-2/p20C/dark/HDR2-0e0-2-20C-dark-temps-1.csv";
  tFile[23] = "20200916_HDR2-2/p20C/dark/HDR2-0e0-2-20C-dark-temps-2.csv";
  int col[6] = { kMagenta-3, kRed-3, kOrange-3, kGreen-3, kCyan-3, kBlue-3 };
  
  double volt[NFILES][MAX];
  double curr[NFILES][MAX];
  int n[NFILES];
  double tempStd[NFILES], tempMea[NFILES];
  double vbr[NFILES];
  double voltD[NFILES][MAX];
  double currN[NFILES][MAX];
  TGraph *grIV[NFILES];
  TGraph *grDCR[NFILES];
  TSpline *spDCR[NFILES];
  for(int i=0; i!=NFILES; ++i) {
    // read ivcurves
    n[i] = readfile( iFile[i], volt[i], curr[i] );
    // read temperatures
    readtemperature( tFile[i], tempMea[i], tempStd[i] );
    vbr[i] = readtemperaturetrend(vbrFile[i/12], tempMea[i], 0);
    cout << "* Breakdown voltage " << vbr[i] << " at " << tempMea[i] << "C "<< endl;
    // scale DCR
    for(int j=0; j!=n[i]; ++j) {
      voltD[i][j] = volt[i][j] - vbr[i];
      currN[i][j] = curr[i][j]/(1.6e-19)/gainenf->Eval( voltD[i][j] ) *1e-9;
    }
    grIV[i]  = new TGraph( n[i], volt[i],  curr[i] );
    if(i<12) {
      grIV[i]->SetMarkerStyle(24);
      //grDCR[i]->SetMarkerStyle(24);
    } else {
      grIV[i]->SetMarkerStyle(25);
      //grDCR[i]->SetMarkerStyle(25);
    }
    //grDCR[i]->SetMarkerColor( col[(i/2)%6] );
    //grDCR[i]->SetLineWidth(0);
    grIV[i]->SetMarkerColor( col[(i/2)%6] );
    grIV[i]->SetLineWidth(0);
    //spDCR[i] = new TSpline3( Form("sp%d",i), grDCR[i]);
  }

  TCanvas *main = new TCanvas();
  TH2D *axis1 = new TH2D("axis1",";Bias  Voltage  (V);Current  (A)",100,0,45,100,1e-12,1e-7);
  main->SetLogy(1);
  TF1 *fitLeak[NFILES];
  axis1->Draw();
  for(int i=0; i!=NFILES; ++i) {
    fitLeak[i] = new TF1( Form("leakFit%d",i), "expo", -10, 80 );
    fitLeak[i]->SetLineColor( col[(i/2)%6] );
    fitLeak[i]->SetParameter(0,-25);
    fitLeak[i]->SetParameter(1,0.04);
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Draw("PSAME");
    for(int j=0; j!=n[i]; ++j) {
      currN[i][j] = (curr[i][j]-fitLeak[i]->Eval(volt[i][j]))/(1.6e-19)/gainenf->Eval( voltD[i][j] ) *1e-9;
      //currN[i][j] = curr[i][j]/(1.6e-19)/gainenf->Eval( voltD[i][j] ) *1e-9;
    }
    grDCR[i] = new TGraph( n[i], voltD[i], currN[i] );
    if(i<12) {
      grDCR[i]->SetMarkerStyle(24);
    } else {
      grDCR[i]->SetMarkerStyle(25);
    }
    grDCR[i]->SetMarkerColor( col[(i/2)%6] );
    grDCR[i]->SetLineWidth(0);
    spDCR[i] = new TSpline3( Form("sp%d",i), grDCR[i]);
  }

  
  TCanvas *main2 = new TCanvas();
  main2->SetLogy(1);
  main2->SetGridx(1);
  main2->SetGridy(1);
  TH2D *axis2 = new TH2D("axis2",";Overvoltage  (V);Dark Count Rate  (I^{sub}/e/gain/enf*1e-9)    (Ghz)",100,0,7,100,1e-6,1e-3);
  axis2->Draw();
  for(int i=0; i!=NFILES; ++i)
    grDCR[i]->Draw("SAMEP");

  TString legs[24] = { "-30C","-30C","-20C","-20C","-10C","-10C","0C","0C","10C","10C","20C","20C",
    "-30C","-30C","-20C","-20C","-10C","-10C","0C","0C","10C","10C","20C","20C" };
  TLegend *leg = new TLegend(0.5,0.12,0.85,0.35,"HDR2      Non-Irradiated");
  TLegend *leg1 = new TLegend(0.1,0.7,0.5,0.9,"HDR2      Non-Irradiated");
  for(int i=0; i!=NFILES/2; ++i) {
    //leg->AddEntry( grDCR[i], iFile[i].Data() );
    leg->AddEntry( grDCR[i], legs[i].Data() );
    leg->AddEntry( grDCR[i+NFILES/2], legs[i+NFILES/2].Data() );
    leg1->AddEntry( grDCR[i], legs[i].Data() );
    leg1->AddEntry( grDCR[i+NFILES/2], legs[i+NFILES/2].Data() );
  }
  leg->SetNColumns(4);
  leg1->SetNColumns(4);
  leg->Draw();
  main2->SaveAs("DCR_HDR2.pdf","pdf");
  main->cd()->SetLogy(1);
  leg1->Draw();

  TCanvas *main3 = new TCanvas();
  main3->SetLogy(1);
  double xT[24] = {-30,-30,-20,-20,-10,-10,0,0,10,10,20,20,-30,-30,-20,-20,-10,-10,0,0,10,10,20,20};
  double yT[4][NFILES];
  cout << Form(" TEMP || 2.5       | 3.0       | 3.5       | 4.0") << endl;
  for(int i=0; i!=NFILES; ++i) {
    yT[0][i] = spDCR[i]->Eval(2.5);
    yT[1][i] = spDCR[i]->Eval(3.0);
    yT[2][i] = spDCR[i]->Eval(3.5);  
    yT[3][i] = spDCR[i]->Eval(4.0);
    cout << Form("%+5.1f || %.3e | %.3e | %.3e | %.3e", tempMea[i], yT[0][i], yT[1][i], yT[2][i], yT[3][i]) << endl;
  }
  TH2D *axis3 = new TH2D("axis3",";Temperature  (C);Dark Count Rate   (Ghz)",100,-32,+22,100,1e-6,1e-3);
  axis3->Draw();
  TGraph *grT[4];
  int colorT[4] = {kBlack, kGray, kGray+1, kYellow-3 };
  for(int i=0; i!=4; ++i) {
    grT[i] = new TGraph(NFILES,tempMea,yT[i]);
    grT[i]->SetMarkerColor( colorT[i]  );
    grT[i]->SetLineWidth(0);
    grT[i]->SetMarkerStyle(20);
    grT[i]->Draw("PSAME");
  }
  TF1 *fitT = new TF1("fitT","expo");
  grT[0]->Fit(fitT);
  grT[0]->Fit(fitT);
  
  TLegend *legT = new TLegend(0.49,0.12,0.89,0.39,"HDR2      Non-Irradiated");
  legT->AddEntry(grT[0],"DCR @ OV=2.5");
  legT->AddEntry(grT[1],"DCR @ OV=3.0");
  legT->AddEntry(grT[2],"DCR @ OV=3.5");
  legT->AddEntry(grT[3],"DCR @ OV=4.0");
  legT->AddEntry(fitT,Form("exp(%f+%f*x)",fitT->GetParameter(0),fitT->GetParameter(1)) );
  legT->Draw();
  return 0;

}
