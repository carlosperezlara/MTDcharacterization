#include "helpers.C"

int overvoltage(TString file="20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-1.csv",
		TString filetemp="20200826_HDR2-2e14/temperatureTrend.txt",
		TString filetempX="20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv" ) {
  gStyle->SetOptStat(0);
  int n=0;
  double volt[MAX]; //original
  double curr[MAX]; //original
  
  ///////
  // my clumsy way of extracting data from a csv file
  double maxY=0;
  TString outfilestring = Form("outputfiles/%s",file.Data());
  std::ifstream fin( outfilestring.Data() );
  std::string line;
  for(;;n++) {
    if(!std::getline(fin,line)) break;
    if(n>MAX) break;
    TString rline = line;
    TObjArray *lst = rline.Tokenize(",");
    volt[n] =  ((TObjString*) lst->At(0))->GetString().Atof();
    curr[n] =  ((TObjString*) lst->At(1))->GetString().Atof()*1e9; // move to nA
    if( curr[n] > maxY ) maxY = curr[n];
  }
  std::cout << "I read " << n << " pairs. My MAX stack was " << MAX << std::endl;
  
  // create graphical objects
  TGraph  *gr0 = new TGraph(n,volt,curr);
  TSpline *sp0 = new TSpline3("sp0",gr0);
  
  // read temperatures
  loadTemperatureTables();
  double temperatureStd, temperatureMea;
  readtemperature(filetempX, temperatureMea, temperatureStd);
  cout << "* "<< temperatureMea << endl;

  // read bvoltage from trend
  double  bvoltage = readtemperaturetrend(filetemp, temperatureMea);
  cout << "* "<< bvoltage << endl;
  

  double overV[100];
  int nov;
  for(nov=0; nov!=100; ++nov) {
    overV[nov] = bvoltage + nov*0.1;
    if(overV[nov] > volt[n-1]) break;
  }

  /////////////
  // D O N E //
  /////////////

  ///////
  // display all
  double min0 = bvoltage - 1;
  double max0 = overV[nov-1] + 1;

  TLine *lin = new TLine();
  lin->SetLineColor(kRed-3);
  TLatex *tex = new TLatex();

  TCanvas *main = new TCanvas();
  //main->SaveAs( Form("%s_OverVoltage.pdf[",outfilestring.Data()), "pdf" );
  //main->cd()->SetLogy(1);
  TH2D *axis0 = new TH2D("axis0","IV-curve;Bias (V);I  (nA)",100, min0, max0 ,10000, 0, maxY );
  axis0->Draw("");
  gr0->Draw("*SAME");
  gr0->SetMarkerColor(kGreen-3);
  sp0->Draw("SAME");
  tex->SetTextSize(0.03);
  tex->DrawTextNDC(0.12,0.85,Form("%s",file.Data()));
  tex->SetTextSize(0.05);
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
  
  return 0;
}
