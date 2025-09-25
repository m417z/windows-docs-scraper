typedef struct _FEATURE_DATA_DVD_READ {
  FEATURE_HEADER Header;
  UCHAR          Multi110 : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          Reserved2;
  UCHAR          DualDashR : 1;
  UCHAR          Reserved3 : 7;
  UCHAR          Reserved4;
} FEATURE_DATA_DVD_READ, *PFEATURE_DATA_DVD_READ;