#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main(int argc,char *argv[]){

	FILE *fp,*of,*f[3];

	t_header h1;
	t_dib dh1;
	char tmp[3]={0,0,0};
	int i,j;
	char *buff,*buff1;
	fp = fopen("googlelogo.bmp","r");
	of = fopen("bmpdata","w+b");
	f[0] = fopen("R.bmp","w+b");
	f[1] = fopen("G.bmp","w+b");
	f[2] = fopen("B.bmp","w+b");
	getfileheader(&h1,fp);
	getdibheader(&dh1,fp);

	for(i=0;i<3;i++){
		writefileheader(h1,f[i]);
		writedibheader(dh1,f[i]);
	}
	
	buff = malloc(dh1.psize);
	buff1 = malloc(451200);
	memset(buff1,0,451200);
	memset(buff,0,dh1.psize);
	

	for(j=0;j<3;j++){
		fread(buff,dh1.psize,1,fp);
		for(i=0;i<dh1.psize;i++){
			if(i%3!=j)
				buff[i]=0;
		}
		fwrite(buff,dh1.psize,1,f[j]);
		memset(buff,0,dh1.psize);
		fseek(fp,h1.offset,SEEK_SET);
	}


	fread(buff,dh1.psize,1,fp);
	for(i=0,j=0;i<451200;i+=4,j+=3){

		buff1[i]=buff[j];
	}
	fwrite(buff1,451200,1,of);
	free(buff);
	fclose(fp);
	fclose(of);
	for(i=0;i<3;i++)
		fclose(f[i]);
	return 0;
}
