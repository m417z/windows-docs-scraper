typedef struct _WSD_DATETIME {
  BOOL  isPositive;
  ULONG year;
  UCHAR month;
  UCHAR day;
  UCHAR hour;
  UCHAR minute;
  UCHAR second;
  UINT  millisecond;
  BOOL  TZIsLocal;
  BOOL  TZIsPositive;
  UCHAR TZHour;
  UCHAR TZMinute;
} WSD_DATETIME;