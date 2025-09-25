typedef struct _CDROM_TOC_ATIP_DATA {
  UCHAR                     Length[2];
  UCHAR                     Reserved1;
  UCHAR                     Reserved2;
  CDROM_TOC_ATIP_DATA_BLOCK Descriptors[0];
} CDROM_TOC_ATIP_DATA, *PCDROM_TOC_ATIP_DATA;