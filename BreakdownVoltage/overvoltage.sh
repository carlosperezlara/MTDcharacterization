#root -l bvfinder.C\(\"20200804_20.8C/HDR2-_Ch4_iLED-1-20200804-1128.csv\",0.1,0.5\);

# -30 DEG (somewhere between -31.25 and -31.15)
#root -b -q bvfinder.C\(\"20200811_n30C/HDR2-_Chdirect_iLED-1-20200811-1303.csv\",0.07,36.8,42.0\); #looking good
#root -b -q bvfinder.C\(\"20200811_n30C/HDR2-_Chdirect_iLED-1-20200811-1306.csv\",0.07,36.8,42.0\); #looking good
##root -b -q bvfinder.C\(\"20200811_n30C/HDR2-_Chdirect_iLED-1-20200811-1308.csv\",0.07,36.8,42.0\); #Looks wrong

# -19 DEG (somewhere between -18.9 and -18.65)
#root -b -q bvfinder.C\(\"20200811_n19C/HDR2-_Chdirect_iLED-1-20200810-1646.csv\",0.07,36.8,42.0\); #Looking good
#root -b -q bvfinder.C\(\"20200811_n19C/HDR2-_Chdirect_iLED-1-20200810-1649.csv\",0.07,36.8,42.0\); #Looking good

# -16 DEG (somewhere between -16.85 and -16.05)
#root -b -q bvfinder.C\(\"20200811_n1617C/HDR2-_Chdirect_iLED-1-20200810-1631.csv\",0.07,36.8,42.0\); #Looking good
#root -b -q bvfinder.C\(\"20200811_n1617C/HDR2-_Chdirect_iLED-1-20200810-1634.csv\",0.07,36.8,42.0\); #Looking good

# -10 DEG (somewhere between -9.7 and -9.1)
#root -b -q bvfinder.C\(\"20200811_n10C/HDR2-_Chdirect_iLED-1-20200810-1601.csv\",0.07,38,42.0\); #Looking good
#root -b -q bvfinder.C\(\"20200811_n10C/HDR2-_Chdirect_iLED-1-20200810-1607.csv\",0.07,38,42.0\); #Looking good
#root -b -q bvfinder.C\(\"20200811_n10C/HDR2-_Chdirect_iLED-1-20200810-1609.csv\",0.07,38,42.0\); #Looking good

# 0102 DEG (somewhere between +1.7 and +1.9)
#root -b -q bvfinder.C\(\"20200811_p0102C/HDR2-_Chdirect_iLED-1-20200810-1452.csv\",0.07,38,42.0\); #Looking good 
#root -b -q bvfinder.C\(\"20200811_p0102C/HDR2-_Chdirect_iLED-1-20200810-1455.csv\",0.07,38,42.0\); #Looking good 
#root -b -q bvfinder.C\(\"20200811_p0102C/HDR2-_Chdirect_iLED-1-20200810-1458.csv\",0.07,38,42.0\); #Looking good 

# 13 DEG (somewhere between +13.35 and +13.65)
##root -b -q bvfinder.C\(\"20200811_p13C/HDR2-_Chdirect_iLED-1-20200812-1224.csv\",0.07,38,42.0\); #Bad
##root -b -q bvfinder.C\(\"20200811_p13C/HDR2-_Chdirect_iLED-1-20200812-1230.csv\",0.07,38,42.0\); #Bad


### NewSiPM - 2

# -30 DEG (somewhere between)
#root -q overvoltage.C\(\"20200815_HDR2-2/n30C/dark/HDR2-2-n30C-dark-1.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n30C/dark/n30C-dark-1st.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/n30C/dark/HDR2-2-n30C-dark-2.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n30C/dark/n30C-dark-2nd.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/n30C/dark/HDR2-2-n30C-dark-3.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n30C/dark/n30C-dark-3rd.csv\"\);

# -20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200815_HDR2-2/n20C/dark/HDR2-2-n20C-dark-1.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n20C/dark/n20C-dark-1st.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/n20C/dark/HDR2-2-n20C-dark-2.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n20C/dark/n20C-dark-2nd.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/n20C/dark/HDR2-2-n20C-dark-3.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n20C/dark/n20C-dark-3rd.csv\"\);

# -10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200815_HDR2-2/n10C/dark/HDR2-2-n10C-dark-1.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n10C/dark/n10C-dark-1st.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/n10C/dark/HDR2-2-n10C-dark-2.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n10C/dark/n10C-dark-2nd.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/n10C/dark/HDR2-2-n10C-dark-3.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/n10C/dark/n10C-dark-3rd.csv\"\);

# 0 DEG (somewhere between)
#root -q overvoltage.C\(\"20200815_HDR2-2/zeroC/dark/HDR2-2-0C-dark-1.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/zeroC/dark/0C-1st.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/zeroC/dark/HDR2-2-0C-dark-2.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/zeroC/dark/0C-2nd.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/zeroC/dark/HDR2-2-0C-dark-3.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/zeroC/dark/0C-3rd.csv\"\);

# +10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200815_HDR2-2/p10C/HDR2-2-10C-dark.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/p10C/10C-temps.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/p10C/HDR2-2-10C-dark-2.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/p10C/10C-temps.csv\"\);

# +20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200815_HDR2-2/p20C/dark/HDR2-2-20C-_Chdirect_iLED-1-20200813-1406.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/p20C/dark/20C.csv\"\);
#root -q overvoltage.C\(\"20200815_HDR2-2/p20C/dark/HDR2-2-20C-_Chdirect_iLED-1-20200813-1408.csv\",\"20200815_HDR2-2/temperatureTrend.txt\",\"20200815_HDR2-2/p20C/dark/20C-2.csv\"\);



# Irradiated NewSiPM 1e13

# -30 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-1.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-1-temps.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-2.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/n30C/dark/HDR2-1e13-n30C-dark-2-temps.csv\"\);

# -20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-1.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-1-temps.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-2.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/n20C/dark/HDR2-1e13-n20C-dark-2-temps.csv\"\);

# -10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-1.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-1-temps.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-2.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/n10C/dark/HDR2-1e13-n10C-dark-2-temps.csv\"\);

# 0 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-1.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-1-temps.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-2.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/zeroC/dark/HDR2-1e13-0C-dark-2-temps.csv\"\);

# +10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-1.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-1-temps.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-2.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/p10C/dark/HDR2-1e13-10C-dark-2-temps.csv\"\);

# +20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-1.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-2.csv\",\"20200826_HDR2-1e13/temperatureTrend.txt\",\"20200826_HDR2-1e13/p22C/dark/HDR2-1e13-21.5C-dark-temps-2.csv\"\);


# Irradiated NewSiPM 5e13

# -30 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-1.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-2.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/n30C/dark/HDR2-5e13-n30C-dark-temps-2.csv\"\);

# -20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-1.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-2.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/n20C/dark/HDR2-5e13-n20C-dark-temps-2.csv\"\);

# -10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-1.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-2.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/n10C/dark/HDR2-5e13-n10C-dark-temps-2.csv\"\);

# 0 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-1.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-2.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/zeroC/dark/HDR2-5e13-0C-dark-temps-2.csv\"\);

# +10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-1.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-2.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/p12C/dark/HDR2-5e13-10C-dark-temps-2.csv\"\);

# +20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-1.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-2.csv\",\"20200826_HDR2-5e13/temperatureTrend.txt\",\"20200826_HDR2-5e13/p18C/dark/HDR2-5e13-18C-dark-temps-2.csv\"\);

# -30 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-1.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-2.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/n30C/dark/HDR2-5e13-2-n30C-dark-temps-2.csv\"\);

# -20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-1.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-2.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/n20C/dark/HDR2-5e13-2-n20C-dark-temps-2.csv\"\);

# -10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-1.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-2.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/n10C/dark/HDR2-5e13-2-n10C-dark-temps-2.csv\"\);

# 0 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-1.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-2.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/zeroC/dark/HDR2-5e13-2-0C-dark-temps-2.csv\"\);

# +10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-1.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-2.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/p10C/dark/HDR2-5e13-2-10C-dark-temps-2.csv\"\);

# +20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-1.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-2.csv\",\"20200831_HDR2-5e13-2/temperatureTrend.txt\",\"20200831_HDR2-5e13-2/p20C/dark/HDR2-5e13-2-20C-dark-temps-2.csv\"\);


# Irradiated NewSiPM 2e14

# -30 DEG (somewhere between)
#root -l overvoltage.C\(\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-2.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-3.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-3.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-4.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n30C/dark/HDR2-2e14-n30C-dark-temps-4.csv\"\);

# -20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n20C/dark/HDR2-2e14-n20C-dark-temps-2.csv\"\);

# -10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/n10C/dark/HDR2-2e14-n10C-dark-temps-2.csv\"\);

# 0 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/zeroC/dark/HDR2-2e14-0C-dark-temps-2.csv\"\);

# +10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200826_HDR2-2e14/p10C/dark/HDR2-2e14-10C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200826_HDR2-2e14/p10C/dark/HDR2-2e14-10C-dark-temps-1.csv\"\);

# -30 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/n30C/dark/HDR2-2e14-2-n30C-dark-temps-2.csv\"\);

# -20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/n20C/dark/HDR2-2e14-2-n20C-dark-temps-2.csv\"\);

# -10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/n10C/dark/HDR2-2e14-2-n10C-dark-temps-2.csv\"\);

# 0 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/zeroC/dark/HDR2-2e14-2-0C-dark-temps-2.csv\"\);

# +10 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/p10C/dark/HDR2-2e14-2-10C-dark-temps-2.csv\"\);

# +20 DEG (somewhere between)
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-1.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-temps-1.csv\"\);
#root -q overvoltage.C\(\"20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-2.csv\",\"20200831_HDR2-2e14-2/temperatureTrend.txt\",\"20200831_HDR2-2e14-2/p20C/dark/HDR2-2e14-2-20C-dark-temps-2.csv\"\);
