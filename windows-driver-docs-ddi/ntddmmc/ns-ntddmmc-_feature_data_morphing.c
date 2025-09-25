typedef struct _FEATURE_DATA_MORPHING {
  FEATURE_HEADER Header;
  UCHAR          Asynchronous : 1;
  UCHAR          OCEvent : 1;
  UCHAR          Reserved01 : 6;
  UCHAR          Reserved2[3];
} FEATURE_DATA_MORPHING, *PFEATURE_DATA_MORPHING;