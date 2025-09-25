typedef struct _HIDSPICX_REPORT {
  UCHAR  ReportType;
  USHORT ReportContentLength;
  UCHAR  ReportId;
  UCHAR  ReportContent[0];
} HIDSPICX_REPORT;