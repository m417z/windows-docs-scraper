typedef struct _FEATURE_DATA_RANDOM_READABLE {
  FEATURE_HEADER Header;
  UCHAR          LogicalBlockSize[4];
  UCHAR          Blocking[2];
  UCHAR          ErrorRecoveryPagePresent : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          Reserved2;
} FEATURE_DATA_RANDOM_READABLE, *PFEATURE_DATA_RANDOM_READABLE;