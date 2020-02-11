#ifndef __rw_spiflash_H__
#define __rw_spiflash_H__

#include "includes.h"
//#include "bsp_w25qxx.h"

#define WLOG_BUFSIZE		80
#define RLOG_BUFSIZE		1024
#define LOG_FILE_MAXSIZE		(10*1024)//log��󳤶�10k
#define LOG_FILE_TRUNCATION_SIZE		1024//log�ļ��ضϳ���
#define LOG_DISPLAY_LINE	13//�����ʾ13��
#define	LOG_DISPLAY_SIZE	500//255//(WLOG_BUFSIZE*LOG_DISPLAY_LINE)//log�ı�����ʾ����ı��ֽ�

#define	FLASH_FREE_MIN		100//flashʣ��ռ�С��100k ��������ע ��Ҫɾ������

extern struct _flashfs flashfs;
extern struct _logbuf logBufer;
//void fs_test();
int FlashFSInit(void);
u8 write_log(char *str);
u32 read_log(char *pbuf);
void CreateLogFile(void);
//u8 WritePerfuseData(char *data);
u8 GetFlashSpace(u32 *ptotal, u32 *pfree);
//u8 GetPerfuseDataFilename(_PerfuseFile_t *pfile/*, u8 *filenum*/);
//u8 CheckPerfuseData(void);

#endif