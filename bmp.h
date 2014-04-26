#include <stdio.h>
typedef struct {
	char MS[2];
	int size;
	short rem1;
	short rem2;
	int offset;
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
	fread((*hd).MS,2,1,ip);
	fread(&(*hd).size,4,1,ip);
	fread(&(*hd).rem1,2,1,ip);
	fread(&(*hd).rem2,2,1,ip);
	fread(&(*hd).offset,4,1,ip);
}

void getdibheader(t_dib *dhd,FILE *ip){
	fseek(ip,14,SEEK_SET);
    fread(&(*dhd).size,4,1,ip);
	fread(&(*dhd).width,4,1,ip);
	fread(&(*dhd).height,4,1,ip);
	fread(&(*dhd).cn,2,1,ip);
	fread(&(*dhd).deep,2,1,ip);
	fread(&(*dhd).method,4,1,ip);
	fread(&(*dhd).psize,4,1,ip);
	fread(&(*dhd).hre,4,1,ip);
	fread(&(*dhd).vre,4,1,ip);
	fread(&(*dhd).pcn,4,1,ip);
	fread(&(*dhd).impc,4,1,ip);
}