typedef union _NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO {
  UINT64 AsUINT64;
  struct {
    UINT32 NumAvailableDestinations : 16;
    UINT32 SourcePortId : 16;
    UINT32 SourceNicIndex : 8;
    UINT32 NativeForwardingRequired : 1;
#if ...
    UINT32 Reserved1 : 1;
#else
    UINT32 Reserved1 : 2;
#endif
    UINT32 IsPacketDataSafe : 1;
    UINT32 SafePacketDataSize : 12;
    UINT32 IsPacketDataUncached : 1;
    UINT32 IsSafePacketDataUncached : 1;
    UINT32 Reserved2 : 7;
  };
} NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO, *PNDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO;