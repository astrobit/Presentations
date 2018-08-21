#include <cstdio>

void Gen_Images(FILE * fileOut, double dY, const char * lpszString)
{
	fprintf(fileOut,"\\draw[yellow] (7.9,%.2f) node {%s};\n",dY+0.75,lpszString);
	fprintf(fileOut,"\\begin{scope}[even odd rule]\n");
	fprintf(fileOut,"\\clip (2,%.2f) circle (0.45);\n",dY);
	fprintf(fileOut,"\\tkzpic{1.5}{%.2f}{1}{1}{Pictures/tycho};\n",dY-0.5);
	fprintf(fileOut,"\\end{scope}\n");
	fprintf(fileOut,"\\begin{scope}[even odd rule]\n");
	fprintf(fileOut,"\\clip (14.5,%.2f) circle (0.25);\n",dY);
	fprintf(fileOut,"\\tkzpic{14.25}{%.2f}{0.5}{0.5}{Pictures/115334main_image_feature_329_ys_full};\n",dY-0.25);
	fprintf(fileOut,"\\end{scope}\n");
}

void Gen_Photon(FILE * fileOut, double dY,size_t tTime, double dH0, double dphi) 
{
	double dX = tTime + 3.1;
	double dXa[7];
	for (int tI = -3; tI <= 3; tI++)
	{
		dXa[tI + 3] = dX + 0.1 * tI + dH0 * tTime * tI + dphi * tTime * tTime * tI * 0.5;
	}

	fprintf(fileOut,"\\draw[white!75!gray,rounded corners] (%.2f,%.2f) -- (%.2f,%.2f) -- (%.2f,%.2f) -- (%.2f,%.2f) -- (%.2f,%.2f) -- (%.2f,%.2f) -- (%.2f,%.2f);\n",
		dXa[0],dY,dXa[1],dY,dXa[2],dY+0.3,dXa[3],dY,dXa[4],dY-0.3,dXa[5],dY,dXa[6],dY); 
}

int main(void)
{

	FILE * fileOut = fopen("ede.tex","wt");
	for (size_t tTime = 0; tTime < 10; tTime++)
	{
		fprintf(fileOut,"\\frame{\\frametitle{Expansion \\& Dark Energy}\n");
		fprintf(fileOut,"\\begin{tikzpicture}\n");
		fprintf(fileOut,"\\draw[opacity=0] (0.1,0.1) rectangle (15.8,9);\n");

		Gen_Images(fileOut,7.5,"No Expansion");
		Gen_Photon(fileOut,7.5,tTime,0.00,0.0);

		Gen_Images(fileOut,5.5,"Constant Expansion");
		Gen_Photon(fileOut,5.5,tTime,0.02,0.0);

		Gen_Images(fileOut,3.5,"Dark Energy");
		Gen_Photon(fileOut,3.5,tTime,0.02,0.003);

		fprintf(fileOut,"\\end{tikzpicture}\n");
		fprintf(fileOut,"}\n");
	}
	return 0;
}
