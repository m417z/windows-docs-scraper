typedef struct _NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_V2 {
  ULONG                        TransmitChecksumOffloadSupported : 4;
  ULONG                        ReceiveChecksumOffloadSupported : 4;
  ULONG                        LsoV2Supported : 4;
  ULONG                        RssSupported : 4;
  ULONG                        VmqSupported : 4;
  ULONG                        UsoSupported : 4;
#if ...
  ULONG                        Reserved : 8;
#else
  ULONG                        Reserved : 12;
#endif
  ULONG                        MaxHeaderSizeSupported;
  union {
    struct {
      USHORT VxlanUDPPortNumber;
      USHORT VxlanUDPPortNumberConfigurable : 1;
    } VxlanInfo;
    ULONG Value;
  } EncapsulationProtocolInfo;
  _ENCAPSULATION_PROTOCOL_INFO _ENCAPSULATION_PROTOCOL_INFO;
  ULONG                        Reserved1;
  ULONG                        Reserved2;
} NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_V2, *PNDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_V2;