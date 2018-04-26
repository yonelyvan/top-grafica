#include <string>

typedef long			LONG;
typedef unsigned long	DWORD;
typedef int				BOOL;
typedef unsigned char   BYTE;
typedef unsigned short	WORD;
typedef BYTE			*LPBYTE;
typedef DWORD			*LPDWORD;


typedef struct tagRGBQUAD
{
	BYTE	rgbBlue;
	BYTE	rgbGreen;
	BYTE	rgbRed;
	BYTE	rgbReserved;
}RGBQUAD;

typedef struct  tagBITMAPFILEHEADER
{  
	WORD	bfType;				
	DWORD	bfSize;				
	WORD	bfReserved1;		
	WORD	bfReserved2;		
	DWORD	bfOffBits;			
}BITMAPFILEHEADER;				

typedef struct tagBITMAPINFOHEADER
{  
	DWORD	biSize;				
	LONG	biWidth;			
	LONG	biHeight;			
	WORD	biPlanes;			
	WORD	biBitCount;			
	DWORD	biCompression;		
	DWORD	biSizeImage;		
	LONG	biXPelsPerMeter;	
	LONG	biYPelsPerMeter;	
	DWORD	biClrUsed;			
	DWORD	biClrImportant;		
}BITMAPINFOHEADER;				
#pragma pack()

class BMP{
	public:
		BMP();
		BMP(const std::string &location);

		~BMP();

	public:
		BYTE*	load(const std::string &location);
		void	save(const std::string &location);
	private:
		void	swap(BYTE **src, DWORD width, DWORD height, WORD channel);

	public:
		LONG	width();
		LONG	height();
		BYTE	depth();
		BYTE*	data();
		WORD	_channels();

	public:
		DWORD	rows;
		DWORD	cols;
		WORD	channels;

	private:
		BITMAPFILEHEADER	*head;  
		BITMAPINFOHEADER	*info;  
		RGBQUAD				*palette;   // color table
		BYTE				*pixels;	// iamge pixel data  

}; /* end for class BMP */
