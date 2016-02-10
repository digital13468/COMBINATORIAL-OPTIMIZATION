#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define V 100

double maxFlow=0.0;
double Edge[V][V]={0.0};
int Resource=79;
int Sink=50;
int Path[V];
int nextVertex(int u, int* Path, int* Explored);
int* Augmentation();
void cutSet(int u, int* cutSet, double* edge, double* cedge);
int cutSetSize=0;                        
main(){
Edge[0][12]=7.4524;
Edge[0][78]=7.507;
Edge[1][92]=2.6319;
Edge[2][84]=3.9031;
Edge[3][86]=4.6054;
Edge[4][45]=8.1446;
Edge[5][8]=6.6196;
Edge[5][85]=6.2713;
Edge[7][6]=0.3872;
Edge[8][19]=4.3818;
Edge[8][77]=5.3193;
Edge[10][2]=7.8235;
Edge[10][78]=8.2298;
Edge[11][56]=0.0092;
Edge[12][72]=5.8034;
Edge[13][17]=7.921;
Edge[13][72]=6.5692;
Edge[14][20]=4.2781;
Edge[15][11]=1.824;
Edge[16][38]=2.9622;
Edge[17][31]=6.456;
Edge[17][93]=7.5806;
Edge[19][11]=1.8966;
Edge[20][68]=3.0536;
Edge[21][80]=2.0546;
Edge[22][43]=1.8564;
Edge[23][87]=4.6364;
Edge[24][94]=4.8018;
Edge[26][36]=8.4837;
Edge[27][61]=5.3629;
Edge[28][38]=3.7939;
Edge[29][14]=5.9547;
Edge[30][8]=7.0785;
Edge[30][85]=6.7301;
Edge[31][68]=3.6235;
Edge[32][55]=3.6884;
Edge[33][98]=2.5446;
Edge[35][12]=7.8729;
Edge[35][85]=7.2926;
Edge[36][45]=7.0864;
Edge[36][99]=6.688;
Edge[37][72]=6.3844;
Edge[38][11]=1.9033;
Edge[39][84]=3.3171;
Edge[40][85]=5.5051;
Edge[42][15]=3.1119;
Edge[42][88]=3.3251;
Edge[44][7]=1.5193;
Edge[45][28]=5.9583;
Edge[46][48]=8.0189;
Edge[47][58]=8.6724;
Edge[49][27]=3.5585;
Edge[51][67]=4.9037;
Edge[52][28]=5.4185;
Edge[52][88]=4.4357;
Edge[53][62]=8.2771;
Edge[54][30]=8.9273;
Edge[55][61]=5.5378;
Edge[56][80]=2.2784;
Edge[59][47]=6.809;
Edge[60][39]=5.4556;
Edge[61][82]=6.498;
Edge[62][96]=6.4225;
Edge[63][45]=8.3637;
Edge[63][99]=7.9654;
Edge[64][66]=3.9632;
Edge[66][9]=1.3564;
Edge[67][82]=6.8541;
Edge[69][7]=1.0283;
Edge[70][17]=7.8061;
Edge[70][75]=7.7176;
Edge[72][15]=3.7809;
Edge[72][88]=3.9941;
Edge[73][36]=8.3762;
Edge[74][22]=4.4028;
Edge[74][88]=4.0847;
Edge[75][62]=7.4369;
Edge[76][50]=9.1997;
Edge[77][66]=3.291;
Edge[78][39]=5.6804;
Edge[79][13]=9.0445;
Edge[79][73]=9.7899;
Edge[80][91]=4.8575;
Edge[82][71]=8.2617;
Edge[84][6]=0.9589;
Edge[85][31]=5.284;
Edge[86][65]=7.8549;
Edge[87][82]=5.946;
Edge[88][44]=2.5903;
Edge[89][80]=3.1996;
Edge[90][78]=7.0985;
Edge[92][27]=3.79;
Edge[93][31]=6.2897;
Edge[94][61]=5.6031;
Edge[95][31]=5.6588;
Edge[95][96]=5.8468;
Edge[96][72]=5.2923;
Edge[97][84]=2.5969;
Edge[99][18]=5.545;
Edge[99][96]=5.8753;
Edge[0][13]=8.2181;
Edge[0][90]=7.9328;
Edge[1][94]=3.9022;
Edge[2][96]=5.7006;
Edge[3][87]=4.0019;
Edge[4][53]=9.2668;
Edge[5][14]=5.8352;
Edge[5][95]=6.646;
Edge[7][9]=0.7362;
Edge[8][20]=5.0625;
Edge[8][85]=5.7514;
Edge[10][4]=9.5351;
Edge[10][90]=8.6557;
Edge[11][81]=0.8307;
Edge[12][74]=5.894;
Edge[13][28]=6.5028;
Edge[13][74]=6.6597;
Edge[14][34]=4.4385;
Edge[15][43]=1.3251;
Edge[16][44]=2.7415;
Edge[17][36]=7.4568;
Edge[17][95]=6.9497;
Edge[19][15]=2.5911;
Edge[20][69]=2.6396;
Edge[21][83]=2.5191;
Edge[22][44]=2.9085;
Edge[23][91]=5.3885;
Edge[25][58]=9.1107;
Edge[26][52]=7.8636;
Edge[27][76]=6.6585;
Edge[28][39]=4.7994;
Edge[29][20]=5.7019;
Edge[30][14]=6.2941;
Edge[30][93]=7.7358;
Edge[31][69]=3.2095;
Edge[32][80]=2.8079;
Edge[34][15]=3.4323;
Edge[35][13]=8.6386;
Edge[35][93]=8.2983;
Edge[36][52]=6.5466;
Edge[37][2]=6.7927;
Edge[37][75]=7.6477;
Edge[38][21]=0.9885;
Edge[39][88]=3.8166;
Edge[41][46]=6.2775;
Edge[42][16]=3.4762;
Edge[42][97]=3.4765;
Edge[44][9]=1.4527;
Edge[45][39]=5.8471;
Edge[46][50]=8.3243;
Edge[47][71]=8.7062;
Edge[49][41]=4.0528;
Edge[51][80]=3.2993;
Edge[52][31]=5.5458;
Edge[52][96]=5.7338;
Edge[53][75]=8.4102;
Edge[54][35]=9.4898;
Edge[55][67]=5.8938;
Edge[56][87]=2.9748;
Edge[59][58]=7.5019;
Edge[60][42]=4.9642;
Edge[61][86]=5.9572;
Edge[62][99]=6.7566;
Edge[63][53]=9.4859;
Edge[64][14]=5.207;
Edge[64][68]=3.9826;
Edge[66][11]=1.5863;
Edge[68][7]=1.4424;
Edge[69][9]=0.9617;
Edge[70][28]=6.3879;
Edge[70][77]=6.202;
Edge[72][16]=4.1452;
Edge[72][97]=4.1455;
Edge[73][52]=7.7561;
Edge[74][28]=5.0675;
Edge[75][2]=6.715;
Edge[75][64]=6.7266;
Edge[76][57]=9.0992;
Edge[77][68]=3.3104;
Edge[78][60]=6.4479;
Edge[79][17]=8.8705;
Edge[79][93]=8.7042;
Edge[80][98]=3.4486;
Edge[82][76]=7.7936;
Edge[84][7]=1.3744;
Edge[85][34]=4.8746;
Edge[86][76]=7.2528;
Edge[87][91]=5.5539;
Edge[88][66]=2.4941;
Edge[89][87]=3.896;
Edge[90][99]=6.8669;
Edge[92][61]=4.3328;
Edge[93][34]=5.8802;
Edge[94][76]=6.8987;
Edge[95][39]=5.4203;
Edge[96][15]=4.0299;
Edge[96][74]=5.3829;
Edge[98][23]=3.9796;
Edge[99][22]=4.8953;
Edge[99][97]=4.7285;
Edge[0][18]=6.6109;
Edge[0][96]=6.9413;
Edge[2][16]=4.5536;
Edge[2][97]=4.5538;
Edge[3][94]=4.2513;
Edge[4][60]=7.7531;
Edge[5][20]=5.5824;
Edge[6][21]=0.3643;
Edge[7][21]=0.0513;
Edge[8][31]=5.6324;
Edge[8][96]=5.8205;
Edge[10][36]=8.4768;
Edge[10][99]=7.9982;
Edge[12][2]=6.2118;
Edge[12][85]=5.9832;
Edge[13][31]=6.63;
Edge[13][75]=7.8325;
Edge[14][42]=4.1181;
Edge[15][56]=0.6853;
Edge[16][84]=2.5966;
Edge[17][40]=6.6771;
Edge[17][96]=6.6441;
Edge[19][66]=2.3535;
Edge[20][81]=2.2786;
Edge[21][98]=2.0942;
Edge[22][66]=2.8122;
Edge[24][27]=4.5616;
Edge[26][4]=9.5419;
Edge[26][54]=9.799;
Edge[27][82]=5.9552;
Edge[28][42]=4.3079;
Edge[29][31]=6.2718;
Edge[30][17]=7.9021;
Edge[31][14]=4.848;
Edge[31][72]=5.1042;
Edge[32][87]=3.5043;
Edge[34][19]=3.505;
Edge[35][17]=8.4646;
Edge[35][95]=7.6674;
Edge[36][60]=6.6949;
Edge[37][12]=7.1445;
Edge[37][78]=7.199;
Edge[38][43]=1.4044;
Edge[39][97]=3.9679;
Edge[41][47]=6.8941;
Edge[42][19]=3.1845;
Edge[43][3]=1.5352;
Edge[44][11]=1.6826;
Edge[45][60]=6.6146;
Edge[46][57]=8.2238;
Edge[47][76]=8.2381;
Edge[49][55]=3.7333;
Edge[51][83]=3.7638;
Edge[52][34]=5.1363;
Edge[53][0]=8.7959;
Edge[53][78]=7.9616;
Edge[54][52]=7.8619;
Edge[55][82]=6.1301;
Edge[56][89]=2.069;
Edge[59][67]=6.1282;
Edge[60][72]=5.6332;
Edge[62][2]=6.5819;
Edge[63][0]=9.0314;
Edge[63][60]=7.9722;
Edge[64][15]=4.2008;
Edge[64][72]=5.4632;
Edge[66][43]=1.0874;
Edge[68][9]=1.3758;
Edge[69][11]=1.1916;
Edge[70][29]=7.6218;
Edge[70][85]=6.6341;
Edge[72][18]=4.962;
Edge[73][4]=9.4345;
Edge[73][64]=7.7344;
Edge[74][31]=5.1948;
Edge[75][12]=7.0667;
Edge[75][72]=6.3067;
Edge[76][65]=9.099;
Edge[77][69]=2.8963;
Edge[78][72]=5.858;
Edge[79][26]=9.8974;
Edge[80][23]=3.94;
Edge[81][1]=0.986;
Edge[83][23]=4.4045;
Edge[84][9]=1.3078;
Edge[85][42]=4.5541;
Edge[86][82]=6.5496;
Edge[87][94]=5.0511;
Edge[88][68]=2.5134;
Edge[89][94]=4.1453;
Edge[91][25]=7.5811;
Edge[92][86]=4.3843;
Edge[93][40]=6.5108;
Edge[94][82]=6.1954;
Edge[95][42]=4.9289;
Edge[96][16]=4.3942;
Edge[96][85]=5.4721;
Edge[98][41]=4.6486;
Edge[99][28]=5.5599;
Edge[0][36]=7.754;
Edge[0][99]=7.2753;
Edge[2][18]=5.3703;
Edge[3][24]=3.7526;
Edge[4][0]=8.8122;
Edge[4][62]=8.2935;
Edge[5][31]=6.1523;
Edge[6][32]=1.1176;
Edge[7][32]=0.7021;
Edge[8][34]=5.2229;
Edge[9][6]=0.3206;
Edge[10][37]=8.7562;
Edge[11][6]=0.5505;
Edge[12][18]=5.722;
Edge[12][88]=4.7542;
Edge[13][36]=7.6308;
Edge[13][78]=7.3838;
Edge[14][66]=3.2871;
Edge[15][66]=2.2809;
Edge[16][88]=3.096;
Edge[17][52]=6.8367;
Edge[18][16]=4.0639;
Edge[19][68]=2.3729;
Edge[20][88]=3.4851;
Edge[22][6]=1.7764;
Edge[22][68]=2.8316;
Edge[24][41]=5.056;
Edge[26][5]=8.4701;
Edge[26][63]=9.7611;
Edge[27][86]=5.4144;
Edge[28][44]=3.5732;
Edge[29][34]=5.8623;
Edge[30][29]=7.7178;
Edge[31][15]=3.8418;
Edge[31][77]=4.8519;
Edge[32][89]=2.5985;
Edge[34][20]=4.1857;
Edge[35][29]=8.2803;
Edge[36][2]=6.5134;
Edge[36][64]=6.5249;
Edge[37][18]=6.303;
Edge[37][90]=7.6249;
Edge[38][44]=2.4565;
Edge[40][14]=5.0691;
Edge[41][58]=7.5871;
Edge[42][22]=3.6432;
Edge[43][6]=0.0516;
Edge[44][21]=0.7678;
Edge[45][72]=6.0247;
Edge[46][58]=8.0558;
Edge[48][50]=9.5971;
Edge[49][80]=2.8529;
Edge[51][87]=3.9957;
Edge[52][40]=5.7668;
Edge[53][2]=7.5553;
Edge[53][90]=8.3874;
Edge[54][70]=8.8313;
Edge[55][86]=5.5893;
Edge[57][50]=9.8019;
Edge[59][91]=5.9723;
Edge[60][74]=5.7238;
Edge[62][12]=6.9337;
Edge[63][4]=9.5023;
Edge[63][62]=8.5126;
Edge[64][19]=4.2735;
Edge[64][74]=5.5538;
Edge[66][56]=0.4477;
Edge[68][11]=1.6057;
Edge[69][43]=0.6927;
Edge[70][31]=6.5151;
Edge[70][93]=7.6397;
Edge[72][22]=4.3122;
Edge[73][5]=8.3626;
Edge[73][70]=8.7255;
Edge[74][34]=4.7853;
Edge[75][18]=6.2253;
Edge[75][74]=6.3972;
Edge[76][71]=8.965;
Edge[77][88]=3.7418;
Edge[78][74]=5.9486;
Edge[79][29]=8.6863;
Edge[80][41]=4.6089;
Edge[81][43]=0.3318;
Edge[83][41]=5.0734;
Edge[84][21]=0.6229;
Edge[85][66]=3.7231;
Edge[87][27]=4.8109;
Edge[88][7]=1.8739;
Edge[88][69]=2.0994;
Edge[90][2]=6.6922;
Edge[91][46]=6.5261;
Edge[92][89]=2.875;
Edge[93][52]=6.6704;
Edge[94][86]=5.6546;
Edge[95][52]=6.0395;
Edge[96][18]=5.2109;
Edge[96][88]=4.2431;
Edge[98][59]=4.5634;
Edge[99][38]=4.4433;
Edge[0][39]=6.5148;
Edge[1][24]=3.4035;
Edge[2][28]=5.3853;
Edge[3][41]=4.5055;
Edge[4][13]=8.6891;
Edge[4][75]=8.4266;
Edge[5][40]=6.3734;
Edge[6][49]=1.1626;
Edge[7][49]=0.747;
Edge[8][42]=4.9025;
Edge[9][32]=0.7687;
Edge[10][53]=9.5187;
Edge[11][9]=0.8995;
Edge[12][28]=5.737;
Edge[12][96]=6.0524;
Edge[13][45]=7.5505;
Edge[13][95]=7.1237;
Edge[14][69]=2.8924;
Edge[15][69]=1.8862;
Edge[17][8]=6.9234;
Edge[17][72]=6.3951;
Edge[18][38]=3.7789;
Edge[19][81]=1.5978;
Edge[21][32]=1.4536;
Edge[22][9]=2.1254;
Edge[22][88]=3.263;
Edge[24][55]=4.7365;
Edge[26][13]=8.9478;
Edge[26][70]=8.833;
Edge[28][11]=3.02;
Edge[28][68]=3.4963;
Edge[29][52]=6.6524;
Edge[30][34]=6.2017;
Edge[31][20]=4.5952;
Edge[32][1]=2.3554;
Edge[32][94]=3.7537;
Edge[34][68]=3.2141;
Edge[35][36]=8.1745;
Edge[36][22]=5.3739;
Edge[36][74]=6.1956;
Edge[37][36]=7.446;
Edge[37][96]=6.6333;
Edge[39][16]=3.9677;
Edge[40][20]=4.8163;
Edge[41][82]=6.4496;
Edge[42][43]=1.9184;
Edge[43][32]=1.0377;
Edge[45][2]=6.433;
Edge[45][78]=6.8393;
Edge[46][76]=7.6216;
Edge[48][58]=9.3285;
Edge[49][87]=3.5493;
Edge[51][98]=3.339;
Edge[52][64]=5.9048;
Edge[53][13]=8.6727;
Edge[54][5]=8.4684;
Edge[54][93]=8.6058;
Edge[55][94]=5.2352;
Edge[58][57]=9.5334;
Edge[60][16]=4.7351;
Edge[60][96]=5.8821;
Edge[62][36]=7.2352;
Edge[63][13]=8.9082;
Edge[63][73]=9.6536;
Edge[64][28]=5.3969;
Edge[64][85]=5.6431;
Edge[66][81]=1.2876;
Edge[68][56]=0.467;
Edge[69][81]=0.8929;
Edge[70][40]=6.7362;
Edge[70][96]=6.7032;
Edge[72][38]=3.8603;
Edge[73][13]=8.8404;
Edge[73][95]=7.8691;
Edge[74][42]=4.4649;
Edge[75][28]=6.2403;
Edge[75][90]=7.5472;
Edge[77][15]=3.5287;
Edge[78][12]=6.6181;
Edge[78][96]=6.1069;
Edge[79][35]=9.5882;
Edge[80][55]=4.2894;
Edge[82][47]=7.5349;
Edge[83][55]=4.7539;
Edge[85][14]=4.9669;
Edge[85][72]=5.2231;
Edge[87][46]=5.774;
Edge[88][11]=2.0372;
Edge[89][24]=3.6467;
Edge[90][18]=6.2025;
Edge[91][58]=7.8357;
Edge[93][5]=7.2769;
Edge[93][77]=5.9765;
Edge[95][14]=5.3417;
Edge[95][72]=5.5979;
Edge[96][28]=5.2259;
Edge[97][6]=1.6096;
Edge[98][83]=3.9131;
Edge[99][42]=4.9573;
Edge[0][37]=8.0334;
Edge[1][3]=2.853;
Edge[2][22]=4.7206;
Edge[3][27]=4.0111;
Edge[4][12]=7.9233;
Edge[4][70]=8.5742;
Edge[5][34]=5.7428;
Edge[6][33]=0.8146;
Edge[7][43]=0.4672;
Edge[8][40]=5.8535;
Edge[9][21]=0.0153;
Edge[10][45]=8.3965;
Edge[11][7]=0.9661;
Edge[12][22]=5.0723;
Edge[12][95]=6.358;
Edge[13][37]=7.9102;
Edge[13][85]=6.749;
Edge[14][68]=3.3064;
Edge[15][68]=2.3003;
Edge[17][5]=7.4432;
Edge[17][64]=6.8151;
Edge[18][22]=4.2309;
Edge[19][69]=1.9588;
Edge[21][23]=2.5856;
Edge[22][7]=2.192;
Edge[22][84]=2.7636;
Edge[24][46]=5.5247;
Edge[26][8]=7.9502;
Edge[26][64]=7.8419;
Edge[27][94]=5.0603;
Edge[28][66]=3.4769;
Edge[29][40]=6.4928;
Edge[30][31]=6.6112;
Edge[31][19]=3.9144;
Edge[31][88]=4.055;
Edge[32][92]=2.4834;
Edge[34][66]=3.1947;
Edge[35][30]=8.6198;
Edge[36][12]=6.8651;
Edge[36][72]=6.105;
Edge[37][28]=6.318;
Edge[37][95]=6.9389;
Edge[38][84]=2.3117;
Edge[40][19]=4.1355;
Edge[41][67]=6.2134;
Edge[42][38]=3.1913;
Edge[43][21]=0.2843;
Edge[44][84]=2.0909;
Edge[45][74]=6.1153;
Edge[46][71]=8.0896;
Edge[48][57]=9.4965;
Edge[49][83]=3.3174;
Edge[51][91]=4.7479;
Edge[52][42]=4.8159;
Edge[53][12]=7.907;
Edge[53][99]=7.7299;
Edge[54][73]=9.6915;
Edge[55][91]=5.738;
Edge[58][50]=9.6339;
Edge[60][2]=6.0416;
Edge[60][95]=6.1878;
Edge[62][18]=6.0922;
Edge[63][12]=8.1425;
Edge[63][70]=8.7933;
Edge[64][20]=4.9542;
Edge[64][77]=5.211;
Edge[66][69]=1.6485;
Edge[68][43]=1.1068;
Edge[69][56]=0.053;
Edge[70][36]=7.516;
Edge[70][95]=7.0088;
Edge[72][28]=4.9769;
Edge[73][8]=7.8427;
Edge[73][93]=8.5;
Edge[74][39]=4.9563;
Edge[75][22]=5.5756;
Edge[75][78]=7.1213;
Edge[77][14]=4.5348;
Edge[78][2]=6.2663;
Edge[78][95]=6.4125;
Edge[79][30]=9.0257;
Edge[80][46]=5.0776;
Edge[81][92]=1.114;
Edge[83][46]=5.5421;
Edge[84][33]=0.1726;
Edge[85][68]=3.7425;
Edge[87][41]=5.3053;
Edge[88][9]=1.8072;
Edge[89][3]=3.0961;
Edge[90][12]=7.0439;
Edge[91][47]=7.1427;
Edge[92][94]=4.0302;
Edge[93][64]=6.6487;
Edge[95][8]=6.1261;
Edge[95][64]=6.0178;
Edge[96][22]=4.5612;
Edge[96][97]=4.3944;
Edge[98][67]=5.0531;
Edge[99][39]=5.4488;
Edge[0][45]=7.6737;
Edge[1][27]=3.662;
Edge[2][38]=4.2687;
Edge[3][46]=4.9741;
Edge[4][17]=8.5151;
Edge[4][78]=7.9779;
Edge[5][52]=6.533;
Edge[6][51]=1.609;
Edge[7][56]=0.1725;
Edge[8][52]=6.0131;
Edge[9][43]=0.4006;
Edge[10][60]=8.005;
Edge[11][21]=0.2146;
Edge[12][39]=5.6259;
Edge[12][99]=6.3864;
Edge[13][52]=7.0107;
Edge[13][96]=6.8181;
Edge[14][81]=2.5314;
Edge[15][81]=1.5252;
Edge[17][12]=7.1552;
Edge[17][74]=6.4857;
Edge[18][39]=4.7844;
Edge[20][15]=3.2719;
Edge[21][33]=1.1505;
Edge[22][11]=2.3553;
Edge[22][97]=3.4144;
Edge[24][61]=5.1044;
Edge[26][17]=8.7738;
Edge[26][73]=9.6932;
Edge[28][15]=3.7145;
Edge[28][88]=3.9277;
Edge[29][64]=6.6308;
Edge[30][40]=6.8323;
Edge[31][28]=5.0378;
Edge[32][3]=2.7045;
Edge[33][23]=3.0359;
Edge[34][69]=2.8;
Edge[35][52]=7.5544;
Edge[36][28]=6.0386;
Edge[36][78]=6.9197;
Edge[37][39]=6.2068;
Edge[37][99]=6.9674;
Edge[39][22]=4.1347;
Edge[40][31]=5.3862;
Edge[41][91]=6.0575;
Edge[42][44]=2.9705;
Edge[43][49]=1.0826;
Edge[45][12]=6.7848;
Edge[45][95]=6.5792;
Edge[46][82]=6.9183;
Edge[48][65]=9.4964;
Edge[49][89]=2.6435;
Edge[52][14]=5.2287;
Edge[52][72]=5.4849;
Edge[53][36]=8.2086;
Edge[54][8]=7.9485;
Edge[55][41]=5.4894;
Edge[56][3]=2.175;
Edge[58][71]=9.3992;
Edge[60][18]=5.5518;
Edge[60][97]=4.7354;
Edge[62][39]=5.996;
Edge[63][17]=8.7342;
Edge[63][75]=8.6457;
Edge[64][31]=5.5241;
Edge[64][88]=4.414;
Edge[67][25]=7.7369;
Edge[68][66]=2.0626;
Edge[70][5]=7.5024;
Edge[70][52]=6.8958;
Edge[71][50]=9.6677;
Edge[72][39]=4.8658;
Edge[73][17]=8.6663;
Edge[74][14]=4.8777;
Edge[74][66]=3.6338;
Edge[75][36]=7.3683;
Edge[75][95]=6.8612;
Edge[77][19]=3.6013;
Edge[78][16]=4.9599;
Edge[78][97]=4.9601;
Edge[79][36]=8.5804;
Edge[80][59]=4.5237;
Edge[82][48]=8.191;
Edge[83][59]=4.9882;
Edge[85][15]=3.9608;
Edge[85][74]=5.3137;
Edge[87][47]=6.3906;
Edge[88][15]=2.7317;
Edge[89][27]=3.9051;
Edge[90][39]=6.1063;
Edge[91][67]=6.462;
Edge[93][8]=6.757;
Edge[93][85]=6.4086;
Edge[95][15]=4.3355;
Edge[95][74]=5.6885;
Edge[96][31]=5.3531;
Edge[97][9]=1.9586;
Edge[98][87]=4.145;
Edge[99][64]=6.0462;
Edge[0][60]=7.2822;
Edge[1][61]=4.2048;
Edge[2][39]=5.2741;
Edge[3][55]=4.186;
Edge[4][35]=9.2327;
Edge[4][95]=7.7178;
Edge[5][64]=6.5113;
Edge[6][56]=0.5881;
Edge[7][81]=0.6674;
Edge[8][64]=5.9915;
Edge[9][49]=0.8137;
Edge[10][62]=8.5454;
Edge[11][32]=0.5388;
Edge[12][42]=5.1344;
Edge[13][5]=7.6173;
Edge[13][60]=7.159;
Edge[13][99]=7.1522;
Edge[14][88]=3.7379;
Edge[16][6]=1.6094;
Edge[17][14]=6.1389;
Edge[17][75]=7.6585;
Edge[18][44]=3.5582;
Edge[20][19]=3.3445;
Edge[21][49]=1.4985;
Edge[22][15]=3.0499;
Edge[23][41]=5.1399;
Edge[24][82]=5.6968;
Edge[26][29]=8.5896;
Edge[26][93]=8.6075;
Edge[28][16]=4.0789;
Edge[28][97]=4.0791;
Edge[29][77]=5.9586;
Edge[30][52]=6.9919;
Edge[31][34]=4.7556;
Edge[32][24]=3.2551;
Edge[33][51]=2.3952;
Edge[34][81]=2.439;
Edge[35][64]=7.5327;
Edge[36][31]=6.1659;
Edge[36][85]=6.2848;
Edge[37][45]=7.3657;
Edge[38][6]=1.3245;
Edge[39][38]=3.6827;
Edge[40][34]=4.9767;
Edge[42][7]=2.254;
Edge[42][66]=2.8743;
Edge[43][56]=0.5081;
Edge[45][16]=5.1266;
Edge[45][96]=6.2736;
Edge[47][48]=8.6355;
Edge[48][71]=9.3624;
Edge[51][23]=3.8303;
Edge[52][15]=4.2225;
Edge[52][74]=5.5755;
Edge[53][37]=8.4879;
Edge[54][13]=8.9461;
Edge[55][46]=5.958;
Edge[56][24]=2.7255;
Edge[59][25]=7.2473;
Edge[60][22]=4.9021;
Edge[60][99]=6.2162;
Edge[62][45]=7.1549;
Edge[63][35]=9.4518;
Edge[63][78]=8.197;
Edge[64][34]=5.1147;
Edge[64][96]=5.7122;
Edge[67][46]=6.682;
Edge[68][69]=1.6679;
Edge[70][8]=6.9825;
Edge[70][64]=6.8742;
Edge[71][57]=9.5672;
Edge[72][42]=4.3743;
Edge[73][29]=8.4821;
Edge[74][15]=3.8715;
Edge[74][68]=3.6532;
Edge[75][39]=6.1291;
Edge[75][96]=6.5556;
Edge[77][20]=4.282;
Edge[78][18]=5.7766;
Edge[78][99]=6.441;
Edge[79][54]=9.8957;
Edge[80][67]=5.0134;
Edge[82][50]=8.4964;
Edge[83][67]=5.4779;
Edge[85][19]=4.0334;
Edge[85][77]=4.9709;
Edge[87][55]=4.9858;
Edge[88][19]=2.8043;
Edge[89][41]=4.3995;
Edge[90][45]=7.2652;
Edge[91][82]=6.6982;
Edge[93][14]=5.9726;
Edge[94][41]=5.5547;
Edge[95][20]=5.0889;
Edge[95][77]=5.3456;
Edge[96][38]=4.1092;
Edge[97][16]=3.2474;
Edge[98][91]=4.8972;
Edge[99][72]=5.6263;
Edge[0][62]=7.8225;
Edge[1][86]=4.2563;
Edge[2][44]=4.0479;
Edge[3][80]=3.3055;
Edge[4][36]=8.2249;
Edge[4][96]=7.4122;
Edge[5][74]=6.182;
Edge[6][80]=1.7187;
Edge[7][89]=1.0937;
Edge[8][72]=5.5715;
Edge[9][56]=0.2392;
Edge[10][63]=9.7542;
Edge[11][43]=0.6305;
Edge[12][60]=6.3933;
Edge[13][8]=7.0974;
Edge[13][64]=6.9891;
Edge[14][15]=3.5247;
Edge[15][7]=1.6607;
Edge[16][9]=1.9584;
Edge[17][28]=6.3288;
Edge[17][77]=6.1429;
Edge[18][84]=3.4133;
Edge[20][42]=3.8653;
Edge[21][51]=1.9449;
Edge[22][16]=3.4142;
Edge[23][59]=5.0548;
Edge[24][86]=5.156;
Edge[26][30]=8.929;
Edge[27][46]=5.7831;
Edge[28][18]=4.8956;
Edge[29][5]=7.259;
Edge[29][85]=6.3907;
Edge[30][70]=7.9612;
Edge[31][42]=4.4352;
Edge[32][27]=3.5135;
Edge[33][80]=2.5049;
Edge[35][5]=8.1609;
Edge[35][70]=8.5237;
Edge[36][39]=5.9275;
Edge[36][95]=6.6596;
Edge[37][60]=6.9742;
Edge[38][7]=1.74;
Edge[39][42]=4.1968;
Edge[40][74]=5.4159;
Edge[42][9]=2.1874;
Edge[42][68]=2.8936;
Edge[43][89]=1.4293;
Edge[45][18]=5.9433;
Edge[45][99]=6.6077;
Edge[47][50]=8.9409;
Edge[49][3]=2.7495;
Edge[51][41]=4.4993;
Edge[52][19]=4.2951;
Edge[52][77]=5.2326;
Edge[53][45]=8.1283;
Edge[54][17]=8.7721;
Edge[55][47]=6.5746;
Edge[56][32]=1.6774;
Edge[59][41]=5.7237;
Edge[60][28]=5.5668;
Edge[61][65]=7.8034;
Edge[62][60]=6.7634;
Edge[63][36]=8.4441;
Edge[63][90]=8.6229;
Edge[64][40]=5.7452;
Edge[65][50]=9.8018;
Edge[67][47]=7.2986;
Edge[68][81]=1.3069;
Edge[70][12]=7.2144;
Edge[70][72]=6.4543;
Edge[71][65]=9.5671;
Edge[72][66]=3.5433;
Edge[73][30]=8.8215;
Edge[74][19]=3.9441;
Edge[74][72]=5.1339;
Edge[75][45]=7.288;
Edge[75][99]=6.8897;
Edge[77][34]=4.4425;
Edge[78][22]=5.1269;
Edge[79][4]=9.6386;
Edge[79][63]=9.8578;
Edge[80][83]=3.8735;
Edge[82][57]=8.3959;
Edge[83][87]=4.5698;
Edge[85][20]=4.7141;
Edge[85][88]=4.1739;
Edge[87][59]=5.2201;
Edge[88][38]=2.8111;
Edge[89][46]=4.8682;
Edge[90][60]=6.8737;
Edge[92][3]=2.981;
Edge[93][20]=5.7198;
Edge[94][46]=6.0233;
Edge[95][22]=4.8668;
Edge[95][85]=5.7777;
Edge[96][39]=5.1147;
Edge[97][38]=2.9625;
Edge[99][2]=6.0347;
Edge[99][74]=5.7169;
Edge[0][2]=7.1007;
Edge[0][75]=7.9556;
Edge[1][89]=2.747;
Edge[2][72]=5.4517;
Edge[3][82]=5.1462;
Edge[4][37]=8.5043;
Edge[4][99]=7.7463;
Edge[5][77]=5.8392;
Edge[6][98]=1.7583;
Edge[8][14]=5.3153;
Edge[8][74]=5.6621;
Edge[10][0]=9.0641;
Edge[10][75]=8.6785;
Edge[11][49]=0.5837;
Edge[12][64]=6.2233;
Edge[13][12]=7.3292;
Edge[13][70]=7.9801;
Edge[14][19]=3.5973;
Edge[15][9]=1.594;
Edge[16][21]=1.2735;
Edge[17][29]=7.5627;
Edge[17][85]=6.575;
Edge[18][97]=4.0641;
Edge[20][66]=3.0343;
Edge[21][56]=0.924;
Edge[22][38]=3.1292;
Edge[23][67]=5.5444;
Edge[24][87]=4.5525;
Edge[26][35]=9.4915;
Edge[27][55]=4.995;
Edge[28][22]=4.2459;
Edge[29][8]=6.7391;
Edge[30][5]=7.5984;
Edge[30][77]=6.298;
Edge[31][66]=3.6041;
Edge[32][49]=2.2519;
Edge[33][83]=2.9694;
Edge[35][8]=7.641;
Edge[35][75]=8.3761;
Edge[36][42]=5.436;
Edge[36][96]=6.354;
Edge[37][62]=7.5146;
Edge[38][9]=1.6734;
Edge[39][44]=3.462;
Edge[40][77]=5.073;
Edge[42][11]=2.4173;
Edge[42][69]=2.4796;
Edge[44][6]=1.1037;
Edge[45][22]=5.2936;
Edge[46][47]=7.3628;
Edge[47][57]=8.8404;
Edge[49][24]=3.3;
Edge[51][59]=4.4141;
Edge[52][20]=4.9759;
Edge[52][85]=5.6647;
Edge[53][60]=7.7368;
Edge[54][29]=8.5879;
Edge[55][59]=5.4042;
Edge[56][49]=1.7224;
Edge[59][46]=6.1924;
Edge[60][38]=4.4502;
Edge[61][76]=7.2013;
Edge[62][78]=6.9882;
Edge[63][37]=8.7234;
Edge[63][95]=7.9369;
Edge[64][42]=4.7942;
Edge[66][7]=1.423;
Edge[67][58]=7.9916;
Edge[69][1]=0.625;
Edge[70][14]=6.1981;
Edge[70][74]=6.5449;
Edge[72][11]=3.0864;
Edge[72][68]=3.5626;
Edge[73][35]=9.384;
Edge[74][20]=4.6249;
Edge[74][77]=4.8816;
Edge[75][60]=6.8965;
Edge[76][48]=8.8943;
Edge[77][42]=4.122;
Edge[78][28]=5.7916;
Edge[79][5]=8.5668;
Edge[79][70]=8.9297;
Edge[80][87]=4.1053;
Edge[82][58]=8.2278;
Edge[83][91]=5.322;
Edge[85][28]=5.1568;
Edge[86][48]=7.6502;
Edge[87][67]=5.7098;
Edge[88][43]=1.5383;
Edge[89][55]=4.08;
Edge[90][62]=7.4141;
Edge[92][24]=3.5315;
Edge[93][29]=7.3963;
Edge[94][47]=6.6399;
Edge[95][28]=5.5315;
Edge[95][88]=4.5487;
Edge[96][42]=4.6233;
Edge[97][44]=2.7417;
Edge[99][16]=4.7283;
Edge[99][95]=6.1809;























	int i,j;
	//int cut[V]={0};	
	double temp=100000.0;
	double cEdge[V][V]={0.0};
	double* cedge=&cEdge[0][0];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			cEdge[i][j]=Edge[i][j];
	int* rsPath = Augmentation();	

//   	printf("\n\n");
//      	for(i=0;i<V;i++)
//    		printf("%d\t",*(rsPath+i));
	

	for(i=0;i<V-1;i++){
		if(*(rsPath+i+1)!=-1 && temp>Edge[*(rsPath+i)][*(rsPath+i+1)])
			temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
		else if(*(rsPath+1)==-1){
			printf("No Initial Solution Found! Program Stops!\n");
			exit(1);
		}
		//printf("%d\n",temp);
	}	
	maxFlow+=temp;



	while(*(rsPath+1)!=-1){
		for(i=0;i<V-1;i++){
 		
 			if(*(rsPath+i+1)!=-1){
 				Edge[*(rsPath+i)][*(rsPath+i+1)]=Edge[*(rsPath+i)][*(rsPath+i+1)]-temp;
 				Edge[*(rsPath+i+1)][*(rsPath+i)]=Edge[*(rsPath+i+1)][*(rsPath+i)]+temp;
 				//printf("Edge[%d][%d]=%d\n",i,j,Edge[i][j]);
			}
		}
		
   		for(i=0;i<V;i++)
// 			//printf("\n");
  			printf("%d\t",*(rsPath+i));
//  			//printf("\n");
//  		}
		printf("\nadded flow value: %lf\n",temp);
		rsPath=NULL;
		rsPath=Augmentation();
		temp=100000.0;
		for(i=0;i<V-1;i++)
			if(*(rsPath+i+1)!=-1&&temp>Edge[*(rsPath+i)][*(rsPath+i+1)]){
				temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
				//printf("%d temp=%d\n",i,temp);
			}
		if(*(rsPath+1)!=-1)
			maxFlow+=temp;printf("The max flow value is %lf\n",maxFlow);
// 		else
// 			for(i=0;i<V;i++)
// 				for(j=;j<V;j++)
// 					if()
	}
//	int rCut=0;
	printf("The max flow value is %lf\n",maxFlow);
// 	for(i=1;i<V;i++)
// 		if(Edge[Resource][i]==0&&cEdge[Resource][i]>0)
// 			rCut++;
// 	int * initialCut=malloc(rCut*sizeof(int));
// 	int x=0;
// 	for(i=1;i<V;i++)
// 		if(Edge[Resource][i]==0&&cEdge[Resource][i]>0){
// 			*(initialCut+x)=i;
// 			x++;
// 		}
// 	int* edge=&Edge[0][0];
// 	int* cedge=&cEdge[0][0];
// 	for(i=0;i<x;i++)
// 		cutSet(i,initialCut,edge,cedge,x);
//   	for(i=0;i<V;i++)
//   		for(j=0;j<V;j++)
//   			printf("Edge[%d][%d]=%d\t",i,j,Edge[i][j]); 
	//int* finalCut;
	double* edge=&Edge[0][0];
	cutSetSize=1;
 	int* initialCut=malloc(1*sizeof(int));
 
 	*(initialCut+0)=Resource;
// 	//int finalCut=0;
	cutSet(Resource,initialCut,edge,cedge);
	printf("cutsize %d\n",cutSetSize);
	printf("The R set includes:\n");
	for(i=0;i<cutSetSize;i++)
		printf("%d ",*(initialCut+i));
	printf("\n");
	int* rBar = malloc((V-cutSetSize)*sizeof(int));
	//printf("%d ",*(rBar+1));
	int rBarIndex=0;
	double minCutValur=0.0;
	for(i=0;i<V;i++)
	  for(j=0;j<cutSetSize;j++)
	    if(*(initialCut+j)!=i){
	      if(j==cutSetSize-1){
		*(rBar+rBarIndex)=i;
		rBarIndex++;
		printf("%d ",*(rBar+rBarIndex-1));
	      }
	    }
	    else
	      break;
	    
	for(i=0;i<V-cutSetSize;i++)
	  for(j=0;j<cutSetSize;j++)
	    if(Edge[*(initialCut+j)][*(rBar+i)]==0&&Edge[*(rBar+i)][*(initialCut+j)]==Edge[*(rBar+i)][*(initialCut+j)]&&cEdge[*(initialCut+j)][*(rBar+i)]>0){
	      minCutValur+=Edge[*(rBar+i)][*(initialCut+j)];
	      printf("\nThe minimum cut value is %lf\n",minCutValur);
	    }
	free(initialCut);
	free(rBar);
}
void cutSet(int u, int * initialCut, double* edge, double* cedge){
	int i,j,k;
	int currentSetSize;
	//printf("BEFORE %d\n",u);
	for(i=0;i<V;i++){
		currentSetSize=cutSetSize;
		if(*(edge+u*V+i)>0){
			//printf("New Cut Might be Found!\n");
			
			int skipFlag=0;
			//int * existingCut=malloc(cutSetSize-1*sizeof(int));
			//int * newCut=malloc(cutSetSize*sizeof(int));
			//*(newNode+0)=i;
			//memcpy(existingCut,initialCut,sizeof(initialCut));
			//increaseSize=1;
			for(k=0;k<currentSetSize;k++){
			  //printf("current set size %d\n",currentSetSize);
			  //printf("%d ",*(initialCut+k));//increaseSize=1;

			    if(*(initialCut+k)==i){
			      skipFlag=1;
			      //printf("Node %d exists already!\n",i);
			     }
			}
			//printf("\n");
			if(skipFlag==0){
			    cutSetSize++;
			    //printf("new cut size %d\n",cutSetSize);
			    initialCut = realloc(initialCut,cutSetSize*sizeof(int));
			    if(!initialCut){
			      printf("error!\n");
			      exit(1);
			    }
			    *(initialCut+cutSetSize-1)=i;
			    //printf("Node %d is added!\n",i);
			    //printf("The new set includes now:\n");
			    for(j=0;j<cutSetSize;j++)
			      printf("%d ",*(initialCut+j));
			    printf("\n");
			    cutSet(i,initialCut,edge,cedge);
			    printf("return to %d",u);
			    for(j=0;j<cutSetSize;j++){
			      printf("%d ",*(initialCut+j));
			      if(!initialCut){
				printf("error!\n");
				exit(1);
			      }
			    }
			}
// 			else
// 			  printf("Node(s) already exists!\n");
			//memcpy(initialCut,exisitingCut,sizeof(newNode));

			//if(increaseSize==1)
			  
			//free(newCut);
		}
	//printf("AFTER %d\n",cutSetSize);
 		else if(i==V-1){
			    printf("No new Nodes Found(%d)!\nThe set is still:(%d,%d)\n",u,currentSetSize,cutSetSize);
			    for(j=0;j<cutSetSize;j++)
			      printf("%d ",*(initialCut+j));
			    printf("\n");
		}
	}
// 			printf("%d %d\n",*(edge+u*V+i),*(cedge+u*V+i));
	//return increaseSize;
}
int * Augmentation(){
	//int Pre[V]={-1};
	int i=0;
	int counter=0;
	int* Explored = malloc(V*sizeof(int));
	for(i=0;i<V;i++){
	  Path[i]=-1;
	  *(Explored+i)=-1;
	}
	int* ptrPath;
	ptrPath=&Path[0];
//  	for(i=0;i<V;i++)
//   		printf("%d\t",*(ptrPath+i));
// 	printf("\n");
	Path[0]=Resource;
	nextVertex(Resource,ptrPath,Explored);
	
 	for(i=0;i<V;i++){
 		//printf("%d\t",*(ptrPath+i));
 		if(*(ptrPath+i)==Sink)
 			counter++;
 	}
 	if(counter==0){
 		printf("No Path Found!\n");
 		for(i=0;i<V;i++)
		  *(ptrPath+i)=-1;
 	}
 	else if(!ptrPath){
	   printf("error!");
	   exit(1);
	}
	return ptrPath;
}

int nextVertex(int u, int* ptrPath, int* Explored){
	int i,j,k,jump;
	int y=0;
	int pre;
	
	//printf("This is node %d (V=%d)\n",u,V);
	for(i=0;i<V;i++){
		//if(y==0)
		jump=0;
		pre=0;
		//suc=0;
				//jump=1;
		if(Edge[u][i]>0.00009&&u!=i){		
			for(k=0;k<V;k++){
				if(*(ptrPath+k)==i||*(Explored+k)==i){
					jump=1;
					//break;
					//suc=k;
				}
				if(*(ptrPath+k)==u){
					pre=k;
					//printf("(%d)%d at %d(%d)\n",i,u,pre,k);
				}
			}
			//printf("jump=%d when i=%d\n",jump,i);
			if(jump==1&&i!=V-1)
				continue;
			else if(jump==1&&i==V-1){
//			  for(j=0;j<V;j++)
				*(ptrPath+pre)=-1;
// 				if(*(ptrPath+j)==u){
 					//*(ptrPath+j)=-1;//
					//printf("1. %d is deleted from position %d.\n",u,pre);
// 					break;
// 						
// 				}
			  continue;
			}
			//printf("Edge[%d][%d] is selected (%lf).\n",u,i,Edge[u][i]);
// 			for(j=0;j<V;j++)
// 			  if(*(Explored+j)==i)
			    
				*(ptrPath+(pre+1))=i;
// 				if(*(ptrPath+j)==u){
// 					*(ptrPath+j+1)=i;
 					//printf("%d is added to posistion %d. (Edge[%d][%d]=%lf)\n",i,pre+1,u,i,Edge[u][i]);
// 					break;
// 				
// 				}
			if(i!=Sink){
				//printf("Search for the next node for %d.\n",i);
				y=nextVertex(i,ptrPath,Explored);	
				//printf("stop before hrer");
				if(y==1){
				  //printf("Path has been found. (%d)\n",i);
					break;
				}
				else{
				  for(j=0;j<V;j++)
				    if(*(Explored+j)==-1){
				      *(Explored+j)=i;
				      break;
				    }
				}
			}
			else{
				y=1;
				//printf("Path has been found. (%d)\n",i);
				break;	
			}
		}
		else if(V-1==i){
			//printf("All other nodes has been reached.\n");
			for(j=0;j<V;j++)
				if(*(ptrPath+j)==u){
					*(ptrPath+j)=-1;
					//printf("2. %d is deleted from position %d.\n",u,j);
				}
		}
//  		else if(V-1!=i)
// 		  printf("V=%d i=%d",V,i);
		
	}
	return y;		

}
