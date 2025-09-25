typedef struct _CDROM_TOC_PMA_DATA {
  UCHAR                         Length[2];
  UCHAR                         Reserved1;
  UCHAR                         Reserved2;
  CDROM_TOC_FULL_TOC_DATA_BLOCK Descriptors[0];
} CDROM_TOC_PMA_DATA, *PCDROM_TOC_PMA_DATA;