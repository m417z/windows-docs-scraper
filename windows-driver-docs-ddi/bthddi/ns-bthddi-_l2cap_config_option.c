typedef struct _L2CAP_CONFIG_OPTION {
  CO_HEADER Header;
  VOID      *DynamicBuffer;
  UCHAR     FixedBuffer[4];
  USHORT    Flags;
} L2CAP_CONFIG_OPTION, *PL2CAP_CONFIG_OPTION;