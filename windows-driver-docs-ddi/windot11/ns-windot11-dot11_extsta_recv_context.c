typedef struct DOT11_EXTSTA_RECV_CONTEXT {
  NDIS_OBJECT_HEADER Header;
  ULONG              uReceiveFlags;
  ULONG              uPhyId;
  ULONG              uChCenterFrequency;
  USHORT             usNumberOfMPDUsReceived;
  LONG               lRSSI;
  UCHAR              ucDataRate;
  ULONG              uSizeMediaSpecificInfo;
  PVOID              pvMediaSpecificInfo;
  ULONGLONG          ullTimestamp;
} DOT11_EXTSTA_RECV_CONTEXT, *PDOT11_EXTSTA_RECV_CONTEXT;