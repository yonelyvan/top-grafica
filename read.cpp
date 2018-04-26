#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct bmpFileHeader{/* 2 bytes de identificación */
	uint32_t size;        /* Tamaño del archivo */
	uint16_t resv1;       /* Reservado */
	uint16_t resv2;       /* Reservado */
	uint32_t offset;      /* Offset hasta hasta los datos de imagen */
} bmpFileHeader;

typedef struct bmpInfoHeader{
	uint32_t headersize;      	/* Tamaño de la cabecera */
	uint32_t width;       		/* Ancho */
	uint32_t height;      		/* Alto */
	uint16_t planes;          	/* Planos de color (Siempre 1) */
	uint16_t bpp;             	/* bits por pixel */
	uint32_t compress;        	/* compresión */
	uint32_t imgsize;     		/* tamaño de los datos de imagen */
	uint32_t bpmx;        		/* Resolución X en bits por metro */
	uint32_t bpmy;        		/* Resolución Y en bits por metro */
	uint32_t colors;      		/* colors used en la paleta */
	uint32_t imxtcolors;      	/* Colores importantes. 0 si son todos */
} bmpInfoHeader;


void TextDisplay(bmpInfoHeader *info, unsigned char *img){
	int x, y;
	static const int reduccionX=6, reduccionY=4;/* Reducimos la resolución vertical y horizontal para que la imagen entre en pantalla */
	static const int umbral=90;/* Si la componente supera el umbral, el color se marcará como 1. */
	static unsigned char colores[9]=" bgfrRGB";/* Asignamos caracteres a los colores en pantalla */
	int r,g,b;

	/* Dibujamos la imagen */
	for (y=info->height; y>0; y-=reduccionY){
		for (x=0; x<info->width; x+=reduccionX){
			b=(img[3*(x+y*info->width)]>umbral);
			g=(img[3*(x+y*info->width)+1]>umbral);
			r=(img[3*(x+y*info->width)+2]>umbral);
			printf("%c", colores[b+g*2+r*4]);
		}
		printf("\n");
	}
}

unsigned char *LoadBMP(char *filename, bmpInfoHeader *bInfoHeader){
	FILE *f;
	bmpFileHeader header;     /* cabecera */
	unsigned char *imgdata;   /* datos de imagen */
	uint16_t type;        /* 2 bytes identificativos */

	f=fopen (filename, "r");
	if (!f){
		return NULL;/* Si no podemos leer, no hay imagen*/
	}

	fread(&type, sizeof(uint16_t), 1, f);/* Leemos los dos primeros bytes */
	if (type !=0x4D42){/* Comprobamos el formato */
		fclose(f);
		return NULL;
	}
	
	fread(&header, sizeof(bmpFileHeader), 1, f);/* Leemos la cabecera de fichero completa */
	fread(bInfoHeader, sizeof(bmpInfoHeader), 1, f);/* Leemos la cabecera de información completa */

	/* Reservamos memoria para la imagen, ¿cuánta?
		 Tanto como indique imgsize */
	imgdata=(unsigned char*)malloc(bInfoHeader->imgsize);

	/* Nos situamos en el sitio donde empiezan los datos de imagen,
	 nos lo indica el offset de la cabecera de fichero*/
	fseek(f, header.offset, SEEK_SET);
	fread(imgdata, bInfoHeader->imgsize,1, f);/* Leemos los datos de imagen, tantos bytes como imgsize */
	fclose(f); /* Cerramos */
	return imgdata; /* Devolvemos la imagen */
}

void DisplayInfo(bmpInfoHeader *info){
	cout<<"Tamaño de la cabecera: "<< info->headersize <<endl;
	cout<<"Anchura: "<< info->width <<endl;
	cout<<"Altura: "<< info->height <<endl;
	cout<<"Planos (1): "<< info->planes <<endl;
	cout<<"Bits por pixel: "<< info->bpp <<endl;
	cout<<"Compresión: "<< info->compress <<endl;
	cout<<"Tamaño de datos de imagen: "<< info->imgsize <<endl;
	cout<<"Resolucón horizontal: "<< info->bpmx <<endl;
	cout<<"Resolucón vertical: "<< info->bpmy <<endl;
	cout<<"Colores en paleta: "<< info->colors <<endl;
	cout<<"Colores importantes: "<< info->imxtcolors <<endl;
}


int main(){
	bmpInfoHeader info;
	unsigned char *img=LoadBMP("img.bmp", &info);
	DisplayInfo(&info);
	//TextDisplay(&info, img);

	return 0;
}