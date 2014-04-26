#include <stdio.h>
#define B 101
#define E 200
#define LEN 1200
typedef struct {
	char MS[2];
	int size;
	short rem1;
	short rem2;
	int offset[2];
}t_header;

typedef struct {
	int size;
	int width;
	int height;
	short cn;
	short deep;
	int method;
	int psize;
	int hre;
	int vre;
	int pcn;
	int impc;
}t_dib;

void writefileheader(t_header hd,FILE *op)
void writedibheader(t_dib dhd,FILE *op)
void getfileheader(t_header *hd,FILE *ip)
void getbidheader(t_dib *dhd,FILE *ip)

int main(int argc,char *argv[]){

	FILE *fp,*of;
	char tmp[LEN]; 	
	int begin,data,i;
	t_header header,nheader;
	t_dib dib,ndib;

	fp = fopen("googlelogo.bmp","r");
	getfileheader(&header,fp);
	getdibheader(&dib,fp);
	ndib = dib;
	nheader = header;

	nheader.size = 54+(E-B+1)*header.width*3;
	ndib.height = E-B+1;
	ndib.psize = nheader.size - 54;
	fseek(fp,0,SEEK_SET);
	of = fopen("section.bmp","w");
	begin=(B-1)*dib.width*3+54;
	data=(E-B+1)*dib.width*3;
	fseek(fp,begin-1,SEEK_SET);
	writefileheader(nheader,of);
	writedibheader(ndib,of);
	for(i=0;i<B-1;i++){
		fread(tmp,400*3,1,fp);
		fwrite(tmp,400*3,1,of);
	}
	
	fclose(fp);
	fclose(of);
	return 0;
}

void writefileheader(t_header hd,FILE *op){
	fwrite(hd.MS,2,1,op);
	fwrite(&hd.size,4,1,op);
	fwrite(&hd.rem1,2,1,op);
	fwrite(&hd.rem2,2,1,op);
	fwrite(&hd.offset,4,1,op);
}

void writedibheader(t_dib dhd,FILE *op){
	fwrite(&dhd.size,4,1,op);
	fwrite(&dhd.width,4,1,op);
	fwrite(&dhd.height,4,1,op);
	fwrite(&dhd.cn,2,1,op);
	fwrite(&dhd.deep,2,1,op);
	fwrite(&dhd.method,4,1,op);
	fwrite(&dhd.psize,4,1,op);
	fwrite(&dhd.hre,4,1,op);
	fwrite(&dhd.vre,4,1,op);
	fwrite(&dhd.pcn,4,1,op);
	fwrite(&dhd.impc,4,1,op);
}

void getfileheader(t_header *hd,FILE *ip){
	fread((*hd).MS,sizeof(header.MS),1,ip);
	fread(&(*hd).size,4,1,ip);
	fread(&(*hd).rem1,2,1,ip);
	fread(&(*hd).rem2,2,1,ip);
	fread(&(*hd).offset,4,1,ip);
}


void getbidheader(t_dib *dhd,FILE *ip){
	fseek(ip,14,SEEK_SET);
    fread(&(*dhd).size,4,1,fp);
	fread(&(*dhd).width,4,1,fp);
	fread(&(*dhd).height,4,1,fp);
	fread(&(*dhd).cn,2,1,fp);
	fread(&(*dhd).deep,2,1,fp);
	fread(&(*dhd).method,4,1,fp);
	fread(&(*dhd).psize,4,1,fp);
	fread(&(*dhd).hre,4,1,fp);
	fread(&(*dhd).vre,4,1,fp);
	fread(&(*dhd).pcn,4,1,fp);
	fread(&(*dhd).impc,4,1,fp);
}
