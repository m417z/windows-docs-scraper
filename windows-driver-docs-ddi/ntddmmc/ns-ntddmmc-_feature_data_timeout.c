typedef struct _FEATURE_DATA_TIMEOUT {
  FEATURE_HEADER Header;
  UCHAR          Group3 : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          Reserved2;
  UCHAR          UnitLength[2];
} FEATURE_DATA_TIMEOUT, *PFEATURE_DATA_TIMEOUT;