typedef struct _FEATURE_DATA_MRW {
  FEATURE_HEADER Header;
  UCHAR          Write : 1;
  UCHAR          DvdPlusRead : 1;
  UCHAR          DvdPlusWrite : 1;
  UCHAR          Reserved01 : 5;
  UCHAR          Reserved2[3];
} FEATURE_DATA_MRW, *PFEATURE_DATA_MRW;