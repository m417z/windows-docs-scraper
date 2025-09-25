typedef struct _FEATURE_DATA_DVD_PLUS_RW {
  FEATURE_HEADER Header;
  UCHAR          Write : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          CloseOnly : 1;
  UCHAR          QuickStart : 1;
  UCHAR          Reserved02 : 6;
  UCHAR          Reserved03[2];
} FEATURE_DATA_DVD_PLUS_RW, *PFEATURE_DATA_DVD_PLUS_RW;