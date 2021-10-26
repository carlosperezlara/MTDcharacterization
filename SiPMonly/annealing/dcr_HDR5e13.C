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

  const int NFILES=24;
  TString iFile[NFILES];
  TString tFile[NFILES];
  TString vbrFile[2] = {"20200826_HDR2-5e13/temperatureTrend.txt",
    "20200831_HDR2-5e13-2/temperatureTrend.txt"};
  
  iFile[ 0] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-1.csv";
  iFile[ 1] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-2.csv";
  iFile[ 2] = "20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-1.csv";
  iFile[ 3] = "20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-2.csv";
  iFile[ 4] = "20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-1.csv";
  iFile[ 5] = "20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-2.csv";
  iFile[ 6] = "20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-1.csv";
  iFile[ 7] = "20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-2.csv";
  iFile[ 8] = "20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-1.csv";
  iFile[ 9] = "20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-2.csv";
  iFile[10] = "20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-1.csv";
  iFile[11] = "20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-2.csv";
  tFile[ 0] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-1.csv";
  tFile[ 1] = "20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-2.csv";
  tFile[ 2] = "20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-temps-1.csv";
  tFile[ 3] = "20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-temps-2.csv";
  tFile[ 4] = "20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-temps-1.csv";
  tFile[ 5] = "20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-temps-2.csv";
  tFile[ 6] = "20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-temps-1.csv";
  tFile[ 7] = "20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-temps-2.csv";
  tFile[ 8] = "20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-temps-1.csv";
  tFile[ 9] = "20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-temps-2.csv";
  tFile[10] = "20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-temps-1.csv";
  tFile[11] = "20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-temps-2.csv";
  iFile[12] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-1.csv";
  iFile[13] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-2.csv";
  iFile[14] = "20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-1.csv";
  iFile[15] = "20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-2.csv";
  iFile[16] = "20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-1.csv";
  iFile[17] = "20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-2.csv";
  iFile[18] = "20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-1.csv";
  iFile[19] = "20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-2.csv";
  iFile[20] = "20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-1.csv";
  iFile[21] = "20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-2.csv";
  iFile[22] = "20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-1.csv";
  iFile[23] = "20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-2.csv";
  tFile[12] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-1.csv";
  tFile[13] = "20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-2.csv";
  tFile[14] = "20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-temps-1.csv";
  tFile[15] = "20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-temps-2.csv";
  tFile[16] = "20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-temps-1.csv";
  tFile[17] = "20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-temps-2.csv";
  tFile[18] = "20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-temps-1.csv";
  tFile[19] = "20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-temps-2.csv";
  tFile[20] = "20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-temps-1.csv";
  tFile[21] = "20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-temps-2.csv";
  tFile[22] = "20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-temps-1.csv";
  tFile[23] = "20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-temps-2.csv";

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
    cout << "* Reading " << iFile[i].Data() << endl;
    n[i] = readfile( iFile[i], volt[i], curr[i] );
    // read temperatures
    cout << "* Reading " << tFile[i].Data() << endl;
    readtemperature( tFile[i], tempMea[i], tempStd[i] );
    vbr[i] = readtemperaturetrend(vbrFile[i/12], tempMea[i], 0);
    cout << "* Breakdown voltage " << vbr[i] << " at " << tempMea[i] << "C "<< endl;
    // scale DCR
    for(int j=0; j!=n[i]; ++j) {
      voltD[i][j] = volt[i][j] - vbr[i];
      //currN[i][j] = curr[i][j]/(1.6e-19)/gain->Eval( voltD[i][j] )*1e-9;
    }
    grIV[i]  = new TGraph( n[i], volt[i],  curr[i] );
    //grDCR[i] = new TGraph( n[i], voltD[i], currN[i] );
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
  TH2D *axis1 = new TH2D("axis1",";Bias  Voltage  (V);Current  (A)",100,0,45,100,1e-12,1e-2);
  main->SetLogy(0);
  axis1->Draw();
  TF1 *fitLeak[NFILES];
  for(int i=0; i!=NFILES; ++i) {
    fitLeak[i] = new TF1( Form("leakFit%d",i), "expo", -10, 80 );
    fitLeak[i]->SetLineColor( col[(i/2)%6] );
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
  //main2->SetGridx(1);
  //main2->SetGridy(1);
  TH2D *axis2 = new TH2D("axis2",";Overvoltage  (V);Dark Count Rate  (I^{sub}/e/gain/enf*1e-9)    (Ghz)",100,0,2,100,1,1e3);
  axis2->Draw();
  for(int i=0; i!=NFILES; ++i)
    grDCR[i]->Draw("SAMEP");
  TString legs[24] = { "-30C","-30C","-20C","-20C","-10C","-10C","0C","0C","10C","10C","20C","20C",
    "-30C","-30C","-20C","-20C","-10C","-10C","0C","0C","10C","10C","20C","20C" };
  TLegend *leg = new TLegend(0.35,0.12,0.88,0.45,"HDR2      #Phi = 5e13");
  for(int i=0; i!=NFILES/2; ++i) {
    //leg->AddEntry( grDCR[i], iFile[i].Data() );
    leg->AddEntry( grDCR[i], Form("%s %.3f",legs[i].Data(),vbr[i]) );
    leg->AddEntry( grDCR[i+NFILES/2], Form("%s %.3f",legs[i+NFILES/2].Data(),vbr[i+NFILES/2]) );
    //leg->AddEntry( grDCR[i], legs[i].Data() );
    //leg->AddEntry( grDCR[i+NFILES/2], legs[i+NFILES/2].Data() );
  }
  leg->SetNColumns(4);
  leg->Draw();
  main2->SaveAs("DCR_HDR2-5e13.pdf","pdf");

  TCanvas *main3 = new TCanvas();
  main3->SetLogy(1);
  double xT[24] = {-30,-30,-20,-20,-10,-10,0,0,10,10,20,20,-30,-30,-20,-20,-10,-10,0,0,10,10,20,20};
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
