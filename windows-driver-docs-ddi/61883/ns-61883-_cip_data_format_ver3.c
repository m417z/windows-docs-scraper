typedef struct _CIP_DATA_FORMAT_VER3 {
  UCHAR    FMT;
  UCHAR    FDF_hi;
  UCHAR    FDF_mid;
  UCHAR    FDF_lo;
  BOOLEAN  bHeader;
  UCHAR    Padding;
  UCHAR    BlockSize;
  UCHAR    Fraction;
  IN ULONG BlockPeriod;
  IN ULONG BlockPeriodRemainder;
  IN ULONG BlocksPerPacket;
} CIP_DATA_FORMAT_VER3, *PCIP_DATA_FORMAT_VER3;