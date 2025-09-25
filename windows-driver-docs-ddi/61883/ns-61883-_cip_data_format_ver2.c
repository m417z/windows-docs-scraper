typedef struct _CIP_DATA_FORMAT_VER2 {
  UCHAR    FMT;
  UCHAR    FDF_hi;
  UCHAR    FDF_mid;
  UCHAR    FDF_lo;
  BOOLEAN  bHeader;
  UCHAR    Padding;
  UCHAR    BlockSize;
  UCHAR    Fraction;
  IN ULONG BlockPeriod;
} CIP_DATA_FORMAT_VER2, *PCIP_DATA_FORMAT_VER2;