const int MAX = 10000;
double xT[MAX], yR[MAX];
int n;

void load() {
  std::ifstream fin( "KT103J2.csv" );
  std::string line;
  n=0;
  for(;;n++) {
    if(!std::getline(fin,line)) break;
    if(n>MAX) break;
    TString rline = line;
    TObjArray *lst = rline.Tokenize(",");
    xT[n] =  ((TObjString*) lst->At(0))->GetString().Atof();
    yR[n] =  ((TObjString*) lst->At(1))->GetString().Atof();
    //std::cout << xT[n] << " " << yR[n] << std::endl;
  }
  std::cout << "I found " << n << " calibration points." << std::endl;
  if(n<10) {
    exit(0);
  }
}

double mintemp(double temp) {
  for(int i=0; i!=n; ++i) {
    if(yR[i]<temp) {
      //std::cout << yR[i] << std::endl;
      return xT[i];
    }
  }
  return -999;
}

int temperature(TString file="") {
  load();

  vector<double> resist;
  std::ifstream fin( file.Data() );
  std::string line;
  for(;;) {
    if(!std::getline(fin,line)) break;
    TString rline = line;
    TObjArray *lst = rline.Tokenize(",");
    resist.push_back( ((TObjString*) lst->At(1))->GetString().Atof() );
  }
  std::cout << "I read " << resist.size() << " values of temperature " << std::endl;
  sort( resist.begin(), resist.end() );
  double temp1 = resist[0];
  double temp2 = resist[resist.size()-1];
  std::cout << "First value " << temp1 << " last value " << temp2 << std::endl;
  double min = mintemp( temp1 );
  double max = mintemp( temp2 );
  std::cout << "Temperature range " << min << ", " << max << std::endl;
  
  return 0;
}
