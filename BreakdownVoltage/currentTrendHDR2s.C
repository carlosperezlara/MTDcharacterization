#include "helpers.C"

void sortme(int n, double x[20], double y[20],
	    double ex[20], double ey[20]
	    ) {
  if(n<2) return;
  for(int i=0; i<n-1; ++i)
    for(int j=0; j<n-i-1; ++j)
      if(x[j] > x[j+1]) { //swapping
	double tmp;
	tmp = x[j];  x[j] = x[j+1];   x[j+1] = tmp;
	tmp = y[j];  y[j] = y[j+1];   y[j+1] = tmp;
	tmp = ex[j]; ex[j] = ex[j+1]; ex[j+1] = tmp;
	tmp = ey[j]; ey[j] = ey[j+1]; ey[j+1] = tmp;
      }
  cout << " ** " << endl;
  for(int i=0; i!=n; ++i) {
    cout << " ***** " << x[i] << " " << y[i] << std::endl;
  }
    
}

int currentTrendHDR2s() {
  loadTemperatureTables();
  int nD[10];
  double xD[10][20], exD[10][20];
  double yL[10][20], eyL[10][20];
  for(int m=0; m!=10; ++m)
    for(int i=20;i!=20;++i)
      eyL[m][i]=0;
  double tmp;
  int m;

  //HDR - 2
  m=1;
  nD[m]=0;
  //
  readtemperature("20200815_HDR2-2/n30C/dark/n30C-dark-1st.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n30C/dark/HDR2-2-n30C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/n30C/dark/n30C-dark-2nd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n30C/dark/HDR2-2-n30C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/n30C/dark/n30C-dark-3rd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n30C/dark/HDR2-2-n30C-dark-3.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200815_HDR2-2/n20C/dark/n20C-dark-1st.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n20C/dark/HDR2-2-n20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/n20C/dark/n20C-dark-2nd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n20C/dark/HDR2-2-n20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/n20C/dark/n20C-dark-3rd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n20C/dark/HDR2-2-n20C-dark-3.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200815_HDR2-2/n10C/dark/n10C-dark-1st.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n10C/dark/HDR2-2-n10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/n10C/dark/n10C-dark-2nd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n10C/dark/HDR2-2-n10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/n10C/dark/n10C-dark-3rd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/n10C/dark/HDR2-2-n10C-dark-3.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200815_HDR2-2/zeroC/dark/0C-1st.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/zeroC/dark/HDR2-2-0C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/zeroC/dark/0C-2nd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/zeroC/dark/HDR2-2-0C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/zeroC/dark/0C-3rd.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/zeroC/dark/HDR2-2-0C-dark-3.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200815_HDR2-2/p10C/10C-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/p10C/HDR2-2-10C-dark.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/p10C/10C-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/p10C/HDR2-2-10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200815_HDR2-2/p20C/dark/20C.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/p20C/dark/HDR2-2-20C-_Chdirect_iLED-1-20200813-1406.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200815_HDR2-2/p20C/dark/20C-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200815_HDR2-2/p20C/dark/HDR2-2-20C-_Chdirect_iLED-1-20200813-1408.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  
  //HDR1e13
  m=2;
  nD[m]=0;
  //
  readtemperature("20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-1-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-2-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-1-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-2-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-1-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-2-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-1-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-2-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-1-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-2-temps.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //

  //HDR5e13 - 1
  m=3;
  nD[m]=0;
  //
  readtemperature("20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //

  //HDR5e13 - 2
  m=4;
  nD[m]=0;
  //
  readtemperature("20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //


  //HDR2e14 - 1
  m=5;
  nD[m]=0;
  //
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-3.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-3.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-4.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-4.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200826_HDR2-2e14/p10C/dark/HDR2-2e14-10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200826_HDR2-2e14/p10C/dark/HDR2-2e14-10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //

  //HDR2e14 - 2
  m=6;
  nD[m]=0;
  //
  readtemperature("20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  readtemperature("20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-temps-1.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-1.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  readtemperature("20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-temps-2.csv",xD[m][nD[m]],exD[m][nD[m]]);
  readovervoltagefile("20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-2.csv", tmp, yL[m][nD[m]] );
  nD[m]++;
  //
  
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////
  //////////////////////////

  
  gStyle->SetOptStat(0);

  TCanvas *main = new TCanvas();
  
  TH2D *axis = new TH2D("axis",";Degrees;I  (nA)",100,-34,+24,100,0.01,2e6);
  axis->GetYaxis()->SetNdivisions(509);
  axis->Draw();
  main->SetLogy(1);

  int colors[10] = {kBlue-3, kBlue-3, kGreen-3, kOrange-3, kOrange-3, kRed-3, kRed-3,
		    kBlack, kBlack, kBlack};
  TF1 *fit1[10];
  TGraphErrors *grL[10];
  TSpline *spL[10];
  for(int mm=1; mm!=7; ++mm) {
    fit1[mm] = new TF1("fit1","TMath::Exp([0]+x*[1])");
    fit1[mm]->SetLineColor( colors[mm] );
    // it turns out tht if you want to do a proper TSpline from a graph
    // the points have to be sorted by X which in this case is not guaranteed
    // because of the order in which we took the runs and their respective temperture
    // solution: sort the points before attaching to TGraph object
    //sortme( nD[mm], xD[mm], yL[mm], exD[mm], eyL[mm] );
    grL[mm] = new TGraphErrors(nD[mm], xD[mm], yL[mm], exD[mm], eyL[mm]);
    grL[mm]->SetMarkerColor( colors[mm] );
    grL[mm]->SetLineColor( colors[mm] );
    grL[mm]->SetMarkerStyle( 20 );
    grL[mm]->Draw("PSAME");
    //spL[mm] = new TSpline3(Form("SP%d",mm), grL[mm]);
    //spL[mm]->Draw("SAME");
    grL[mm]->Fit(fit1[mm],"WW");
}
  /*
  double nx[1] = {23.5};
  double ny[1] = {38.4};
  double enx[1] = {0};
  double eny[1] = {0.1};
  TGraphErrors *nominal = new TGraphErrors(1,nx,ny,enx,eny);
  nominal->Draw("*SAME");
  */  
  TLegend *leg = new TLegend(0.14,0.30,0.38,0.65);
  leg->AddEntry(grL[1],"HDR2-2");
  leg->AddEntry(grL[2],"HDR2-1e13");
  leg->AddEntry(grL[3],"HDR2-5e13-1");
  leg->AddEntry(grL[4],"HDR2-5e13-2");
  leg->AddEntry(grL[5],"HDR2-2e14-1");
  leg->AddEntry(grL[6],"HDR2-2e14-2");
  leg->Draw();
  
  main->SaveAs("outputfiles/currentTrendHDR2s.pdf","PDF");

  TCanvas *main2 = new TCanvas();
  
  //TH2D *axis2 = new TH2D("axis2",";Rad;I  (nA)",100,1e-14,2.5e14,100,0.01,2e6);
  TH2D *axis2 = new TH2D("axis2",";Ln Rad;I  (nA)",100,-5,40,100,1e-4,2e6);
  axis2->GetYaxis()->SetNdivisions(509);
  axis2->Draw();
  //main2->SetLogx(1);
  main2->SetLogy(1);

  double xS[6] = {1,1e13,5e13,5e13,2e14,2e14};
  for(int mm=1; mm!=7; ++mm)
    xS[mm-1] = TMath::Log(xS[mm-1]);
  double yS[4][6];
  TGraph *grS[4];
  TF1 *fitS[4];
  TF1 *fitSE[4];
  double temp[4] = {-30,-20,0,+10};
  //int colorT[4] = {kCyan-3,kGray, kMagenta-3, kBlack};
  int colorT[4] = {kBlue-3,kCyan-3, kOrange-3, kRed-3};
  TLegend *leg2 = new TLegend(0.56,0.15,0.88,0.41);
  for(int tt=0; tt!=4; ++tt) {
    for(int mm=1; mm!=7; ++mm) {
      yS[tt][mm-1] = fit1[mm]->Eval( temp[tt] );
      cout << yS[mm-1] << endl;
    }
    fitS[tt] = new TF1(Form("fitS%d",tt),"TMath::Exp([0]+x*[1])",25,35);
    fitS[tt]->SetLineColor( colorT[tt] );
    grS[tt] = new TGraph(6,xS,yS[tt]);
    grS[tt]->SetLineColor( colorT[tt] );
    grS[tt]->SetMarkerColor( colorT[tt] );
    grS[tt]->SetMarkerStyle(20);
    grS[tt]->Draw("PSAME");
    grS[tt]->Fit(fitS[tt],"R","",25,35);
    fitSE[tt] = new TF1(Form("fitSE%d",tt),Form("TMath::Exp(%f+x*%f)", fitS[tt]->GetParameter(0), fitS[tt]->GetParameter(1)),0,40);
    fitSE[tt]->SetLineStyle(9);
    fitSE[tt]->SetLineWidth(1);
    fitSE[tt]->SetLineColor( colorT[tt] );
    fitSE[tt]->Draw("SAME");
    fitS[tt]->Draw("SAME");
    leg2->AddEntry(grS[tt], Form("%+.0fC  |  x RAD^{%.2f}",temp[tt],fitS[tt]->GetParameter(1)) );
  }
  leg2->Draw();
  main2->SaveAs("outputfiles/currentTrendHDR2s_interesting.pdf","PDF");

  return 0;
}
