typedef struct _CDROM_READ_TOC_EX {
  UCHAR Format : 4;
  UCHAR Reserved1 : 3;
  UCHAR Msf : 1;
  UCHAR SessionTrack;
  UCHAR Reserved2;
  UCHAR Reserved3;
} CDROM_READ_TOC_EX, *PCDROM_READ_TOC_EX;