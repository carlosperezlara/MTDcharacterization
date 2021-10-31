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

int dcr_HDR5e13() {
  gStyle->SetOptStat(0);

  loadTemperatureTables();

  // read bvoltage from trend
  // load gain
  LoadGain();
  cout << gainenf->GetFormula()->GetExpFormula() << endl;

  const int NFILES=10;
  TString iFile[NFILES];
  TString tFile[NFILES];
  TString vbrFile = "input/MTD-5e13/temperatureTrend.txt";
  
  iFile[ 0] = "input/MTD-5e13/MTD-SiPM-5e13-1-neg30C-dark.csv";
  iFile[ 1] = "input/MTD-5e13/MTD-SiPM-5e13-1-neg20C-dark.csv";
  iFile[ 2] = "input/MTD-5e13/MTD-SiPM-5e13-1-neg10C-dark.csv";
  iFile[ 3] = "input/MTD-5e13/MTD-SiPM-5e13-1-0C-dark.csv";
  iFile[ 4] = "input/MTD-5e13/MTD-SiPM-5e13-1-15C-dark.csv";

  iFile[ 5] = "input/MTD-5e13/MTD-SiPM-5e13-2-neg30C-dark.csv";
  iFile[ 6] = "input/MTD-5e13/MTD-SiPM-5e13-2-neg20C-dark.csv";
  iFile[ 7] = "input/MTD-5e13/MTD-SiPM-5e13-2-neg10C-dark.csv";
  iFile[ 8] = "input/MTD-5e13/MTD-SiPM-5e13-2-0C-dark.csv";
  iFile[ 9] = "input/MTD-5e13/MTD-SiPM-5e13-2-15C-dark.csv";

  tFile[ 0] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-1-neg30C-dark.csv.csv";
  tFile[ 1] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-1-neg20C-dark.csv.csv";
  tFile[ 2] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-1-neg10C-dark.csv.csv";
  tFile[ 3] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-1-0C-dark.csv.csv";
  tFile[ 4] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-1-15C-dark.csv.csv";

  tFile[ 5] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-2-neg30C-dark.csv.csv";
  tFile[ 6] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-2-neg20C-dark.csv.csv";
  tFile[ 7] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-2-neg10C-dark.csv.csv";
  tFile[ 8] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-2-0C-dark.csv.csv";
  tFile[ 9] = "input/MTD-5e13/humidity_MTD-SiPM-5e13-2-15C-dark.csv.csv";

  //int col[6] = { kMagenta-3, kRed-3, kOrange-3, kGreen-3, kCyan-3, kBlue-3 };
  int col[5] = { kBlue-3, kCyan-3, kGreen-3, kOrange-3, kRed-3 };

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
    cout << "* Reading " << iFile[i].Data() << endl;
    n[i] = readfile_directly( iFile[i], volt[i], curr[i] );
    // read temperatures
    cout << "* Reading " << tFile[i].Data() << endl;
    readtemperature_directly( tFile[i], tempMea[i], tempStd[i] );
    vbr[i] = readtemperaturetrend_directly(vbrFile, tempMea[i], 0);
    cout << "* Breakdown voltage " << vbr[i] << " at " << tempMea[i] << "C "<< endl;
    // scale DCR
    for(int j=0; j!=n[i]; ++j) {
      voltD[i][j] = volt[i][j] - vbr[i];
      //currN[i][j] = curr[i][j]/(1.6e-19)/gain->Eval( voltD[i][j] )*1e-9;
    }
    grIV[i]  = new TGraph( n[i], volt[i],  curr[i] );
    //grDCR[i] = new TGraph( n[i], voltD[i], currN[i] );
    if(i<10) {
      grIV[i]->SetMarkerStyle(20);
      //grDCR[i]->SetMarkerStyle(24);
    } else {
      grIV[i]->SetMarkerStyle(20);
      //grDCR[i]->SetMarkerStyle(25);
    }
    //grDCR[i]->SetMarkerColor( col[(i/2)%6] );
    //grDCR[i]->SetLineWidth(0);
    grIV[i]->SetMarkerColor( col[i%5] );
    grIV[i]->SetLineWidth(0);
    //spDCR[i] = new TSpline3( Form("sp%d",i), grDCR[i]);
  }
  
  TCanvas *main = new TCanvas();
  TH2D *axis1 = new TH2D("axis1",";Bias  Voltage  (V);Current  (A)",100,0,45,100,1e-12,1e-2);
  main->SetLogy(0);
  axis1->Draw();
  TF1 *fitLeak[NFILES];
  for(int i=0; i!=NFILES; ++i) {
    fitLeak[i] = new TF1( Form("leakFit%d",i), "expo", -10, 80 );
    fitLeak[i]->SetLineColor( col[i%5] );
    fitLeak[i]->SetParameter(0,-25);
    fitLeak[i]->SetParameter(1,0.04);
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Fit( fitLeak[i], "RWWQ", "", 20,35 );
    grIV[i]->Draw("SAMEP");
    for(int j=0; j!=n[i]; ++j) {
      currN[i][j] = (curr[i][j]-fitLeak[i]->Eval(volt[i][j]))/(1.6e-19)/gainenf->Eval( voltD[i][j] ) *1e-9;
    }
    grDCR[i] = new TGraph( n[i], voltD[i], currN[i] );
    if(i<10) {
      grDCR[i]->SetMarkerStyle(20);
    } else {
      grDCR[i]->SetMarkerStyle(20);
    }
    grDCR[i]->SetMarkerColor( col[i%5] );
    grDCR[i]->SetLineWidth(0);
    spDCR[i] = new TSpline3( Form("sp%d",i), grDCR[i]);
  }

  TCanvas *main2 = new TCanvas();
  main2->SetLogy(1);
  //main2->SetGridx(1);
  //main2->SetGridy(1);
  TH2D *axis2 = new TH2D("axis2",";Overvoltage  (V);Dark Count Rate  (I^{sub}/e/gain/enf*1e-9)    (Ghz)",100,0,4,100,0.1,3e2);
  axis2->Draw();
  for(int i=0; i!=NFILES; ++i)
    grDCR[i]->Draw("SAMEP");
  TString legs[NFILES] = { "-30C","-20C","-10C","0C","15C",
    "-30C","-20C","-10C","0C","15C" };
  TLegend *leg = new TLegend(0.35,0.12,0.88,0.45,"HDR2      #Phi = 5e13  (annealed)");
  for(int i=0; i!=NFILES/2; ++i) {
    //leg->AddEntry( grDCR[i], Form("%s %.3f",legs[i].Data(),vbr[i]) );
    leg->AddEntry( grDCR[i], Form("%.1f C   V_{br} %.1f",tempMea[i],vbr[i]) );
    leg->AddEntry( grDCR[i+NFILES/2], Form("%.1f %.1f",tempMea[i+NFILES/2],vbr[i+NFILES/2]) );
  }
  leg->SetNColumns(4);
  leg->Draw();
  main2->SaveAs("DCR_HDR2-5e13.root","root");

  TCanvas *main3 = new TCanvas();
  main3->SetLogy(1);
  double xT[20] = {-30,-30,-20,-20,-10,-10,0,0,15,15,-30,-30,-20,-20,-10,-10,0,0,15,15};
  double yT[2][NFILES];
  cout << Form(" TEMP || 0.2       | 0.4") << endl;
  for(int i=0; i!=NFILES; ++i) {
    yT[0][i] = spDCR[i]->Eval(0.2);
    yT[1][i] = spDCR[i]->Eval(0.4);
    cout << Form("%+5.1f || %.3e | %.3e", tempMea[i], yT[0][i], yT[1][i]) << endl;
  }
  TH2D *axis3 = new TH2D("axis3",";Temperature  (C);Dark Count Rate  (Ghz)",100,-32,+22,100,1,1e3);
  axis3->Draw();
  TGraph *grT[4];
  int colorT[4] = {kBlack, kGray, kGray+1, kYellow-3 };
  for(int i=0; i!=2; ++i) {
    grT[i] = new TGraph(NFILES,tempMea,yT[i]);
    grT[i]->SetMarkerColor( colorT[i]  );
    grT[i]->SetLineWidth(0);
    grT[i]->SetMarkerStyle(20);
    grT[i]->Draw("PSAME");
  }
  TF1 *fitT = new TF1("fitT","expo");
  grT[0]->Fit(fitT);
  grT[0]->Fit(fitT);

  TLegend *legT = new TLegend(0.47,0.16,0.87,0.36,"HDR2      #Phi = 5e13");
  legT->AddEntry(grT[0],"DCR @ OV=0.2");
  legT->AddEntry(grT[1],"DCR @ OV=0.4");
  legT->AddEntry(fitT,Form("exp(%f+%f*x)",fitT->GetParameter(0),fitT->GetParameter(1)) );
  legT->Draw();

  return 0;
}
