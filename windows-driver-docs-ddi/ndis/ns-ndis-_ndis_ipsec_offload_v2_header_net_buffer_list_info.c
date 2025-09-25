typedef struct _NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO {
  union {
    struct {
      ULONG NextHeader : 8;
      ULONG PadLength : 8;
      ULONG AhHeaderOffset : 8;
      ULONG EspHeaderOffset : 8;
    } Transmit;
    struct {
      ULONG NextHeader : 8;
      ULONG PadLength : 8;
      ULONG HeaderInfoSet : 1;
    } Receive;
  };
} NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO, *PNDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO;