typedef struct _MPIO_PASS_THROUGH_PATH_DIRECT_EX {
  ULONG     PassThroughOffset;
  ULONG     Version;
  USHORT    Length;
  UCHAR     Flags;
  UCHAR     PortNumber;
  ULONGLONG MpioPathId;
} MPIO_PASS_THROUGH_PATH_DIRECT_EX, *PMPIO_PASS_THROUGH_PATH_DIRECT_EX;