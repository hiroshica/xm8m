/*
	Skelton for retropc emulator

	Author : Takeda.Toshiya
	Date   : 2006.08.18 -

	[ file i/o ]
*/

#ifndef _FILEIO_H_
#define _FILEIO_H_

#include "common.h"

#define FILEIO_READ_BINARY		1
#define FILEIO_WRITE_BINARY		2
#define FILEIO_READ_WRITE_NEW_BINARY	4
#define FILEIO_SEEK_SET			0
#define FILEIO_SEEK_CUR			1
#define FILEIO_SEEK_END			2

class FILEIO
{
private:
#ifdef SDL
	void *fp;
	bool readonly;
#else
	FILE *fp;
#endif // SDL

public:
	FILEIO();
	~FILEIO();
	bool IsProtected(_TCHAR *filename);
	bool Fopen(_TCHAR *filename, int mode);
	void Fclose();
	bool IsOpened();

	bool FgetBool();
	void FputBool(bool val);
	uint8 FgetUint8();
	void FputUint8(uint8 val);
	uint16 FgetUint16();
	void FputUint16(uint16 val);
	uint32 FgetUint32();
	void FputUint32(uint32 val);
	uint64 FgetUint64();
	void FputUint64(uint64 val);
	int8 FgetInt8();
	void FputInt8(int8 val);
	int32 FgetInt32();
	void FputInt32(int32 val);
	double FgetDouble();
	void FputDouble(double val);

	uint32 FgetUint32_LE();

	int Fgetc();
	uint32 Fread(void* buffer, uint32 size, uint32 count);
	uint32 Fwrite(void* buffer, uint32 size, uint32 count);
	uint32 Fseek(long offset, int origin);
	uint32 Ftell();
	static void Remove(_TCHAR *filename);
};

#endif
