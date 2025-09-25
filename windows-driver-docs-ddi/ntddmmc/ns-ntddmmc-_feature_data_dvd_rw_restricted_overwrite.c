typedef struct _FEATURE_DATA_DVD_RW_RESTRICTED_OVERWRITE {
  FEATURE_HEADER Header;
  UCHAR          Blank : 1;
  UCHAR          Intermediate : 1;
  UCHAR          DefectStatusDataRead : 1;
  UCHAR          DefectStatusDataGenerate : 1;
  UCHAR          Reserved0 : 4;
  UCHAR          Reserved1[3];
} FEATURE_DATA_DVD_RW_RESTRICTED_OVERWRITE, *PFEATURE_DATA_DVD_RW_RESTRICTED_OVERWRITE;