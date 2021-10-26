#include "helpers.C"

void shiftx(TGraph *gr, double dx) {
  for(int i=0; i!=gr->GetN(); ++i) {
    gr->SetPointX( i, gr->GetPointX(i) + dx*1e-3 );
  }
}

//int ivcurve(TString filelight="20200915_HDR2-1/n30C/light/HDR2-0e0-1-n30C-257nA-Orange-1.csv", 
//	    TString fileref="20200915_HDR2-1/n30C/dark/HDR2-0e0-1-n30C-dark-1.csv" ) {
int ivcurve(TString filelight="20200831_HDR2-2e14-2/n30C/light/HDR2-2e14-2-n30C-12mA-Orange-1.csv",
	    TString fileref="20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-1.csv", double shiftX=0 ) {

  TString outputfilename;
  {
    TObjArray *objarray = filelight.Tokenize("/");
    int n = objarray->GetEntries();
    outputfilename += ((TObjString*) objarray->At(n-1))->GetString();
  }
  outputfilename += "_";
  {
    TObjArray *objarray = fileref.Tokenize("/");
    int n = objarray->GetEntries();
    outputfilename += ((TObjString*) objarray->At(n-1))->GetString();
  }
  outputfilename += "_IVCURVE";
  
  gStyle->SetOptStat(0);
  double vlight[MAX];
  double clight[MAX];
  double vref[MAX];
  double cref[MAX];
  double csub[MAX];

  // create graphical objects
  TGraph  *grlight  = new TGraph( filelight.Data(), "%lg,%lg");
  TGraph  *grref    = new TGraph( fileref.Data(), "%lg,%lg");
  shiftx(grref,shiftX);
  TSpline *spref    = new TSpline3("spref",grref);

  int nlight = grlight->GetN();
  int nref = grref->GetN();
  cout << " NLIGHT " << nlight << " || NREF " << nref << endl;
  for(int i=0; i!=nlight; ++i) {
    vlight[i] = grlight->GetPointX(i);
    clight[i] = grlight->GetPointY(i);
  }
  for(int i=0; i!=nref; ++i) {
    vref[i] = grref->GetPointX(i);
    cref[i] = grref->GetPointY(i);
  }

  
  // subtract reference
  subtractreference( nlight, vlight, clight, spref, csub );
  //subtractreference2( nlight, clight, cref, csub );
  TGraph  *grsub    = new TGraph(nlight,vlight,csub  );
  
  /////////////
  // D O N E //
  /////////////

  
  ///////
  // display all
  double max0, max1;
  double min0, min1;
  peak( 0,nlight,clight,max0);
  floor(0,nlight,clight,min0);
  peak( 0,nref,cref,max1);
  floor(0,nref,cref,min1);
  std::cout << "min0 " << min0 << " max0 " << max0 << std::endl;
  std::cout << "min1 " << min1 << " max1 " << max1 << std::endl;

  TLine *lin = new TLine();
  lin->SetLineColor(kRed-3);
  TLatex *tex = new TLatex();

  TCanvas *main = new TCanvas();
  main->cd()->SetLogy(1);
  TH2D *axis0 = new TH2D("axis0","IV-curve;Bias  (V);I  (A)",100,0, vref[nref-1],10000,1e-12,1);
  axis0->Draw("");
  grlight->Draw("PSAME");
  grref->Draw("PSAME");
  grsub->Draw("LSAME");
  
  grsub->SetMarkerStyle(20);
  grsub->SetLineColor(kBlack);
  grsub->SetMarkerColor(kBlack);
  grref->SetMarkerStyle(20);
  grref->SetLineColor(kGreen-3);
  grref->SetMarkerColor(kGreen-3);
  grlight->SetMarkerStyle(20);
  grlight->SetLineColor(kRed-3);
  grlight->SetMarkerColor(kRed-3);

  TLegend *leg = new TLegend(0.1,0.7,0.4,0.9);
  leg->AddEntry(grlight,"LIGHT");
  leg->AddEntry(grref,"DARK");
  leg->AddEntry(grsub,"SUBTRACTED");
  leg->Draw();
  
  main->SaveAs( Form("outputfiles/%s.pdf",outputfilename.Data()), "pdf" );
  
  ///// Saving fit data
  //std::cout << outputfilename.Data() << std::endl;
  ofstream fout( Form("outputfiles/%s.csv",outputfilename.Data()) );
  for(int i=0; i!=nlight; ++i) {
    fout << Form("%11e, %11e\n", vlight[i], csub[i]);
  }
  
  return 0;
}
