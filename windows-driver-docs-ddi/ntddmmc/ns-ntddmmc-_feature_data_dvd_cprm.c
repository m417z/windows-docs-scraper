typedef struct _FEATURE_DATA_DVD_CPRM {
  FEATURE_HEADER Header;
  UCHAR          Reserved0[3];
  UCHAR          CPRMVersion;
} FEATURE_DATA_DVD_CPRM, *PFEATURE_DATA_DVD_CPRM;