typedef struct _FEATURE_HEADER {
  UCHAR FeatureCode[2];
  UCHAR Current : 1;
  UCHAR Persistent : 1;
  UCHAR Version : 4;
  UCHAR Reserved0 : 2;
  UCHAR AdditionalLength;
} FEATURE_HEADER, *PFEATURE_HEADER;