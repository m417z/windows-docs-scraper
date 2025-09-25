typedef struct _HIDP_REPORT_IDS {
  UCHAR  ReportID;
  UCHAR  CollectionNumber;
  USHORT InputLength;
  USHORT OutputLength;
  USHORT FeatureLength;
} HIDP_REPORT_IDS, *PHIDP_REPORT_IDS;