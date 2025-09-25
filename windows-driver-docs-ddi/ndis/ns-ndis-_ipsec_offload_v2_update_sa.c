typedef struct _IPSEC_OFFLOAD_V2_UPDATE_SA {
  NDIS_OBJECT_HEADER         Header;
  NDIS_HANDLE                OffloadHandle;
  IPSEC_OFFLOAD_V2_OPERATION Operation;
  IPSEC_OFFLOAD_V2_SPI_TYPE  Spi;
  ULONG                      SequenceNumberHighOrder;
} IPSEC_OFFLOAD_V2_UPDATE_SA, *PIPSEC_OFFLOAD_V2_UPDATE_SA;