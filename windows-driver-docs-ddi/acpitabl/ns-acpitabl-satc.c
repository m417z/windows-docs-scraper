typedef struct _SATC {
  UCHAR       Flags;
  UCHAR       Reserved;
  USHORT      SegmentNumber;
  DEVICESCOPE DeviceScope[ANYSIZE_ARRAY];
} SATC, *PSATC;