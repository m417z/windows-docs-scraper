typedef struct _MSiSCSI_NICConfig {
  ULONG LinkSpeed;
  ULONG MaxLinkSpeed;
  ULONG LinkState;
  ULONG MaxFrameSize;
  UCHAR MacAddress[6];
} MSiSCSI_NICConfig, *PMSiSCSI_NICConfig;