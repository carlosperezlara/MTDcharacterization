const int MAX_WAVES = 500;
const double firstPeak = 0.511;
const double secondPeak = 1.275;
const int CHANNELS = 4;
const int SAMPLES = 1024;

int waveTrainDRS(TString inputfile="20200930_DRS/9-30-2020-4ch-SiPM-LYSO-69V.dat", bool nofit=false) {
  std::cout << "=====================" << std::endl;
  std::cout << "= Source file: " << inputfile.Data() << std::endl;
  std::cout << "=====================" << std::endl;

  std::ifstream inf( inputfile.Data() , std::ifstream::binary);
  
  gStyle->SetOptStat(0);
  int col = 0;
  int color[4] = { kOrange-3, kCyan-3, kMagenta-3, kGreen-3 };
  int nevt = 0;

  char  *c4Tmp = new char [4];
  char  *c2Tmp = new char [2];
  int   iTmp;
  //RUN HEADER
  inf.read(c4Tmp, 4);
  std::cout << c4Tmp << " | ";
  inf.read(c4Tmp, 4);
  std::cout << c4Tmp << " | "; 
  inf.read(c2Tmp, 2);
  std::cout << c2Tmp << " | ";
  inf.read((char*) &iTmp, 2);
  std::cout << iTmp << std::endl; 
  //looping over each channel getting time
  float time[CHANNELS][SAMPLES];  //This is the time of a sample in ns with time[0] = 0
  for(int ich=0; ich!=CHANNELS; ++ich) {
    inf.read(c4Tmp, 4);
    std::cout << "Channel " << ich << ": " << c4Tmp << std::endl;
    inf.read((char*) &time[ich], sizeof(float)*SAMPLES); //This gets the time values in nanoseconds for each sample in the buffer.
    for(int isa=1; isa!=SAMPLES; ++isa) {
      time[ich][isa] += time[ich][isa-1];
      //std::cout << "  Channel " << ich << " sample " << i << " " << time[ich][i] << std::endl;
    }
    std::cout << "   TIME [ " << time[ich][0] << ", " << time[ich][SAMPLES-1] << " ]" << std::endl;
  }

  double minX = time[0][0];
  double maxX = time[0][1023];
  TH1D* fTmp = new TH1D( "Wave", "Wave;Time  (ns);Signal  (mV)", SAMPLES, minX, maxX );
  TH2D *axis[CHANNELS];
  TH1D *integral[CHANNELS];
  for(int ich=0; ich!=CHANNELS; ++ich) {
    axis[ich] = new TH2D(Form("axis_%d",ich),Form("File: %s  Channel %d;Time  (ns);Signal  (mV)",inputfile.Data(),ich),512,minX,maxX,150,-500,+50);
    integral[ich] = new TH1D(Form("charge_%d",ich),Form("File: %s  Channel %d;charge  (a.u.)",inputfile.Data(),ich),100,-7e4,0);
    integral[ich]->SetLineColor(color[ich]);
    integral[ich]->SetMarkerColor(color[ich]);
    integral[ich]->SetMarkerStyle(24);
  }
  std::cout << "*****" << std::endl;
  //TRAILER
  char *c5Tmp = new char[5];
  short s8Tmp[8];
  ushort ch[CHANNELS][SAMPLES];
  double chmV[CHANNELS][SAMPLES]; //This is the voltage recorded on channel 1 in mV
  int nsamp = 200;
  double meanrms[4] = {0,0,0,0};
  while(!inf.eof()) {
    //if (nevt%500==0)
    //std::cout << "Processing event #" << nevt << std::endl;
    //EVENT HEADER
    inf.read(c4Tmp, 4);
    std::cout << c4Tmp << " | ";
    inf.read((char *) &iTmp, 4);
    std::cout << iTmp << " | [ ";
    inf.read((char *) &s8Tmp, 16); //8x2
    for(int i=0; i!=8; ++i)
      std::cout << s8Tmp[i] << " ";
    inf.read((char*) &iTmp, 4);
    std::cout << "] | "<< iTmp << " ";
    inf.read((char*) &iTmp, 4);
    std::cout << iTmp << std::endl;
    //Reading the values of each sample in the buffer for an event
    for(int ich=0; ich!=CHANNELS; ++ich) {
      inf.read(c4Tmp, 4);
      inf.read((char*) &iTmp, 4);
      inf.read((char*) &ch[ich], SAMPLES*2); // SAMPLES*sizeof(ushort)
      //Converting raw value to mV
      double sxx = 0;
      for (int isa=0; isa!=SAMPLES; ++isa) {
	chmV[ich][isa] = 1000*(ch[ich][isa]/65535.-0.5);
	fTmp->SetBinContent(isa+1,chmV[ich][isa]);
	axis[ich]->Fill( time[ich][isa], chmV[ich][isa] );
	if(isa<nsamp) {
	  sxx += chmV[ich][isa]*chmV[ich][isa];
	}
      }
      meanrms[ich] += sqrt( (sxx/nsamp) ); // adding rms of wave x
      int binCenter = fTmp->GetMinimumBin();
      int binMin = binCenter -100;// - 100;
      int binMax = binCenter +200;//+ 500;
      double val = fTmp->Integral( binMin, binMax );
      integral[ich]->Fill(val);      
    }
    nevt++;
    
    if (inf.eof()) {
      std::cout << "End of file reached ......." << std::endl;
      std::cout << "Processed " << nevt << " events ..." << std::endl;
      //endoffile = true;
      break;
    }
  }
  inf.close();
  for(int i=0; i!=4; ++i)
    meanrms[i] /= nevt;

  TLatex *tex = new TLatex();
  TBox *lin = new TBox();

  TCanvas *main = new TCanvas();
  main->Divide(2,2);
  for(int i=0; i!=4; ++i) {
    main->cd(i+1)->SetLogz(1);
    axis[i]->Draw("colz");
    tex->SetTextSize(0.04);
    tex->SetTextColor( kBlack );
    tex->DrawLatexNDC(0.13,0.18, Form("< RMS_{%d} > = %.2f mV",nsamp,meanrms[i]) );
    double nsamp_x = fTmp->GetXaxis()->GetBinLowEdge(nsamp+1);
    cout << " ***** " << minX << " |||| " << nsamp_x << endl;
    lin->SetFillColor(kBlack);
    lin->DrawBox(minX,-460,nsamp_x,-470);
  }
  //main->SaveAs( Form("%s_OSC.png",file.Data()), "PNG" );

  TCanvas *main2 = new TCanvas();
  main2->Divide(2,2);
  TF1 *fit[4];
  TF1 *fit1[4];
  TF1 *fit2[4];
  for(int i=0; i!=4; ++i) {
    main2->cd(i+1);//->SetLogy(1);
    integral[i]->Draw("E");
    if(!nofit) {
      fit[i] = new TF1(Form("fit_%d",i),Form("[4]*([0]*TMath::Gaus(x,[1],[2],1)+(1-[0])*TMath::Gaus(x,[1]*%f,[3],1))",secondPeak/firstPeak),-1.1e5,0);
      double scale = nevt*integral[i]->GetBinWidth(1);
      std::cout << " *****> " << scale << std::endl;
      fit[i]->SetParNames("f1","mu1","sg1","sg2","evts");
      fit[i]->SetParameter(0,0.6);   fit[i]->SetParLimits(0,0.3,0.9);
      fit[i]->SetParameter(1,-3e4);  fit[i]->SetParLimits(1,-4e4,-1e4);
      fit[i]->SetParameter(2,3e3);   fit[i]->SetParLimits(2,1e3,6e3);
      fit[i]->SetParameter(3,3e3);   fit[i]->SetParLimits(3,1e3,6e3);
      fit[i]->SetParameter(4,scale); fit[i]->SetParLimits(4,scale*0.6,scale*1.2);
      integral[i]->Fit(fit[i],"l");
      double chi2 =  fit[i]->GetChisquare() / fit[i]->GetNDF();
      for(int k=0;k!=10;++k) {
	chi2 =  fit[i]->GetChisquare() / fit[i]->GetNDF();
	cout << "last chi2 " << chi2 << endl;
	if(chi2<2) break;
	integral[i]->Fit(fit[i],"emi");
      }
      fit1[i] = new TF1(Form("firstComp_%d",i),Form("%f*TMath::Gaus(x,%f,%f,1)",fit[i]->GetParameter(4)*fit[i]->GetParameter(0),
						    fit[i]->GetParameter(1),fit[i]->GetParameter(2)),-1.1e5,0);
      fit2[i] = new TF1(Form("seconComp_%d",i),Form("%f*TMath::Gaus(x,%f,%f,1)",fit[i]->GetParameter(4)*(1-fit[i]->GetParameter(0)),
						    fit[i]->GetParameter(1)*secondPeak/firstPeak,fit[i]->GetParameter(3)),-1.1e5,0);
      fit1[i]->SetLineColor( kBlack );
      fit2[i]->SetLineColor( kBlack );
      fit1[i]->Draw("same");
      fit2[i]->Draw("same");
      fit[i]->Draw("same");
      tex->SetTextColor( kRed-3 );
      tex->SetTextSize(0.045);
      tex->DrawLatexNDC(0.13,0.82, Form("eN ( a gauss( #mu_{1}, #sigma_{1} ) + (1-a) gaus( #mu_{1}*#frac{1.275}{0.511}, #sigma_{2}\
 ) )"));
      tex->SetTextSize(0.04);
      tex->SetTextColor( kBlack );
      tex->DrawLatexNDC(0.13,0.75, Form( "e = %.0f%%",fit[i]->GetParameter(4)*100/scale));
      tex->DrawLatexNDC(0.13,0.70, Form( "a = %.0f%%",fit[i]->GetParameter(0)*100));
      tex->DrawLatexNDC(0.13,0.65, Form( "#sigma_{1} = %.0f",fit[i]->GetParameter(2)));
      tex->DrawLatexNDC(0.13,0.60, Form( "#sigma_{2} = %.0f",fit[i]->GetParameter(3)));
      tex->DrawLatexNDC(0.13,0.18, Form( "#chi^{2}/NDF = %.2f",chi2));
      tex->SetTextColor( kBlue-3 );
      tex->DrawLatexNDC(0.13,0.55, Form( "#mu_{1} = %.0f",fit[i]->GetParameter(1)));
    }
  }
  //main2->SaveAs( Form("%s_CHARGE.pdf",file.Data()), "PDF" );

  
  return 0;

}
