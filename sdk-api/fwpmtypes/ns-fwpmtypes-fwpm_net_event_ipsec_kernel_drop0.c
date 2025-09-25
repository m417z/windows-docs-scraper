typedef struct FWPM_NET_EVENT_IPSEC_KERNEL_DROP0_ {
  INT32         failureStatus;
  FWP_DIRECTION direction;
  IPSEC_SA_SPI  spi;
  UINT64        filterId;
  UINT16        layerId;
} FWPM_NET_EVENT_IPSEC_KERNEL_DROP0;