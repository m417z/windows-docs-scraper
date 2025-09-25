typedef struct _FEATURE_DATA_DVD_PLUS_R {
  FEATURE_HEADER Header;
  UCHAR          Write : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          Reserved2[3];
} FEATURE_DATA_DVD_PLUS_R, *PFEATURE_DATA_DVD_PLUS_R;