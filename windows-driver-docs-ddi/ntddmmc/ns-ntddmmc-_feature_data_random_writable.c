typedef struct _FEATURE_DATA_RANDOM_WRITABLE {
  FEATURE_HEADER Header;
  UCHAR          LastLBA[4];
  UCHAR          LogicalBlockSize[4];
  UCHAR          Blocking[2];
  UCHAR          ErrorRecoveryPagePresent : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          Reserved2;
} FEATURE_DATA_RANDOM_WRITABLE, *PFEATURE_DATA_RANDOM_WRITABLE;