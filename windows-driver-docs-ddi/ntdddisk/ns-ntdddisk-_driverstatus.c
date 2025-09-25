typedef struct _DRIVERSTATUS {
  UCHAR bDriverError;
  UCHAR bIDEError;
  UCHAR bReserved[2];
  ULONG dwReserved[2];
} DRIVERSTATUS, *PDRIVERSTATUS, *LPDRIVERSTATUS;