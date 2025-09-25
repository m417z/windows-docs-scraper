typedef struct _CDROM_TOC_FULL_TOC_DATA_BLOCK {
  UCHAR SessionNumber;
  UCHAR Control : 4;
  UCHAR Adr : 4;
  UCHAR Reserved1;
  UCHAR Point;
  UCHAR MsfExtra[3];
  UCHAR Zero;
  UCHAR Msf[3];
} CDROM_TOC_FULL_TOC_DATA_BLOCK, *PCDROM_TOC_FULL_TOC_DATA_BLOCK;