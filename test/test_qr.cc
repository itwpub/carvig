#include <carvig.h>

int main(int argc, char **argv)
{
    double A[6*3]={
            -1.71421300000000,	1.53466000000000,	-1.99845900000000,
            -1.51402200000000,	1.07856400000000,	-1.90335600000000,
            -1.71513100000000,	1.52927700000000,	-1.98473900000000,
            -1.52784600000000,	1.08325500000000,	-1.90933900000000,
            -1.71521000000000,	1.53300400000000,	-1.99302600000000,
            -1.52070500000000,	1.08117800000000,	-1.90668500000000
    };
    double B[6*6]={
            -0.431786679495559,	0.390992331294193,	0.528333627870302,	0.331725108405367,	-0.520856966266614,	0.0146734823993782    ,
            -0.381361319779528,	-0.423199793612810,	0.423731930132468,	-0.447206549969361,	0.128566940050776,	-0.528576932374831    ,
            -0.432017911070501,	0.373978649606436,	-0.585109156027243,	-0.495676004589587,	-0.273247355938081,	-0.103869873557569    ,
            -0.384843395261016,	-0.441378360759770,	-0.442269454108007,	0.620621494688544,	-0.0731564390089100	,-0.266374791416326   ,
            -0.432037810084031,	0.384145554179648,	0.0388198825223176,	0.164632609683749,	0.793257288873018,	0.0889242265150905   ,
            -0.383044675569660,	-0.431026956292508,	0.0430447588524446,	-0.178871788584250,	-0.0539022649963072,	0.794190856960230
    };
    double C[20*5]={
            0.537667139546100,	0.671497133608081,	-0.102242446085491,	-1.08906429505224,	1.41931015064255  ,
            1.83388501459509,	-1.20748692268504,	-0.241447041607358,	0.0325574641649735,	0.291584373984183  ,
            -2.25884686100365,	0.717238651328839,	0.319206739165502,	0.552527021112224,	0.197811053464361   ,
            0.862173320368121,	1.63023528916473,	0.312858596637428,	1.10061021788087,	1.58769908997406     ,
            0.318765239858981,	0.488893770311789,	-0.864879917324457,	1.54421189550395,	-0.804465956349547    ,
            -1.30768829630527,	1.03469300991786,	-0.0300512961962686,	0.0859311331754255,	0.696624415849607  ,
            -0.433592022305684,	0.726885133383238,	-0.164879019209038,	-1.49159031063761,	0.835088165072682       ,
            0.342624466538650,	-0.303440924786016,	0.627707287528727,	-0.742301837259857,	-0.243715140377952      ,
            3.57839693972576,	0.293871467096658,	1.09326566903948,	-1.06158173331999,	0.215670086403744       ,
            2.76943702988488,	-0.787282803758638,	1.10927329761440,	2.35045722400204,	-1.16584393148205       ,
            -1.34988694015652,	0.888395631757642,	-0.863652821988714,	-0.615601881466894,	-1.14795277889859       ,
            3.03492346633185,	-1.14707010696915,	0.0773590911304249,	0.748076783703985,	0.104874716016494       ,
            0.725404224946106,	-1.06887045816803,	-1.21411704361541,	-0.192418510588264,	0.722254032225002       ,
            -0.0630548731896562,	-0.809498694424876,	-1.11350074148676,	0.888610425420721,	2.58549125261624    ,
            0.714742903826096,	-2.94428416199490,	-0.00684932810334806,	-0.764849236567874,	-0.666890670701386  ,
            -0.204966058299775,	1.43838029281510,	1.53263030828475,	-1.40226896933876,	0.187331024578940        ,
            -0.124144348216312,	0.325190539456198,	-0.769665913753682,	-1.42237592509150,	-0.0824944253709554,
            1.48969760778547,	-0.754928319169703,	0.371378812760058,	0.488193909859941,	-1.93302291785099 ,
            1.40903448980048,	1.37029854009523,	-0.225584402271252,	-0.177375156618825,	-0.438966153934773,
            1.41719241342961,	-1.71151641885370,	1.11735613881447,	-0.196053487807333,	-1.79467884145512
    };
    double At[6*3],Q[6*6],R[6*3],Bt[6*6],Ct[20*5];
    matt(A,6,3,At);
    matt(B,6,6,Bt);
    matt(C,20,5,Ct);

    tracemat(3,At,6,3,12,6);

    qr(At,6,3,Q,R,0);

    tracemat(3,Q,6,6,12,6);
    tracemat(3,R,6,3,12,6);

    double Q1[6*6],R1[6*6];
    qr(Bt,6,6,Q1,R1,0);

    tracemat(3,Q1,6,6,12,6);
    tracemat(3,R1,6,6,12,6);

    double Q2[20*20],R2[20*5];
    qr(Ct,20,5,Q2,R2,0);

    tracemat(3,Q2,20,20,12,6);
    tracemat(3,R2,20,5,12,6);

    return 0;
}