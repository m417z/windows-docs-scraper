typedef struct _CDROM_TOC_FULL_TOC_DATA {
  UCHAR                         Length[2];
  UCHAR                         FirstCompleteSession;
  UCHAR                         LastCompleteSession;
  CDROM_TOC_FULL_TOC_DATA_BLOCK Descriptors[0];
} CDROM_TOC_FULL_TOC_DATA, *PCDROM_TOC_FULL_TOC_DATA;