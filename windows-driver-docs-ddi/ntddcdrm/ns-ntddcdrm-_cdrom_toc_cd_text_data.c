typedef struct _CDROM_TOC_CD_TEXT_DATA {
  UCHAR                        Length[2];
  UCHAR                        Reserved1;
  UCHAR                        Reserved2;
  CDROM_TOC_CD_TEXT_DATA_BLOCK Descriptors[0];
} CDROM_TOC_CD_TEXT_DATA, *PCDROM_TOC_CD_TEXT_DATA;