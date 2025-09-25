typedef struct _FEATURE_DATA_SMART {
  FEATURE_HEADER Header;
  UCHAR          FaultFailureReportingPagePresent : 1;
  UCHAR          Reserved1 : 7;
  UCHAR          Reserved02[3];
} FEATURE_DATA_SMART, *PFEATURE_DATA_SMART;