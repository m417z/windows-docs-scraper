typedef struct _CDROM_WRITE_SPEED_DESCRIPTOR {
  UCHAR MixedReadWrite : 1;
  UCHAR Exact : 1;
  UCHAR Reserved1 : 1;
  UCHAR WriteRotationControl : 2;
  UCHAR Reserved2 : 3;
  UCHAR Reserved3[3];
  UCHAR EndLba[4];
  UCHAR ReadSpeed[4];
  UCHAR WriteSpeed[4];
} CDROM_WRITE_SPEED_DESCRIPTOR, *PCDROM_WRITE_SPEED_DESCRIPTOR;