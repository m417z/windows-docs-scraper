typedef struct _NDIS_NDK_CAPABILITIES {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              MaxQpCount;
  ULONG              MaxCqCount;
  ULONG              MaxMrCount;
  ULONG              MaxPdCount;
  ULONG              MaxInboundReadLimit;
  ULONG              MaxOutboundReadLimit;
  ULONG              MaxMwCount;
  ULONG              MaxSrqCount;
  ULONG64            MissingCounterMask;
  NDK_ADAPTER_INFO   *NdkInfo;
} NDIS_NDK_CAPABILITIES, *PNDIS_NDK_CAPABILITIES;