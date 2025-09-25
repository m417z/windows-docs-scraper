typedef struct _NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD {
  ULONG TransmitChecksumOffloadSupported : 4;
  ULONG ReceiveChecksumOffloadSupported : 4;
  ULONG LsoV2Supported : 4;
  ULONG RssSupported : 4;
  ULONG VmqSupported : 4;
  ULONG UsoSupported : 4;
  ULONG Reserved : 8;
  ULONG MaxHeaderSizeSupported;
} NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD, *PNDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD;