typedef struct _SendRNIDV2_IN {
  UCHAR PortWWN[8];
  UCHAR DestWWN[8];
  ULONG DestFCID;
  ULONG NodeIdDataFormat;
} SendRNIDV2_IN, *PSendRNIDV2_IN;