typedef struct _NDIS_UDP_SEGMENTATION_OFFLOAD {
  struct {
    ULONG Encapsulation;
    ULONG MaxOffLoadSize;
    ULONG MinSegmentCount : 6;
    ULONG SubMssFinalSegmentSupported : 1;
#if ...
    ULONG Reserved : 25;
#else
    ULONG Reserved : 26;
#endif
  } IPv4;
  struct {
    ULONG Encapsulation;
    ULONG MaxOffLoadSize;
    ULONG MinSegmentCount : 6;
    ULONG SubMssFinalSegmentSupported : 1;
#if ...
    ULONG Reserved1 : 25;
#else
    ULONG Reserved1 : 26;
#endif
    ULONG IpExtensionHeadersSupported : 2;
    ULONG Reserved2 : 30;
  } IPv6;
} NDIS_UDP_SEGMENTATION_OFFLOAD, *PNDIS_UDP_SEGMENTATION_OFFLOAD;