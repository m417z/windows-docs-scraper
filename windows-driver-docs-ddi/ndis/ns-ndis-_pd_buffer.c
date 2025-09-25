typedef struct _PD_BUFFER {
  struct _PD_BUFFER   *NextPDBuffer;
  struct _PD_BUFFER   *NextPartialPDBuffer;
  PVOID               PDClientReserved;
  PVOID               PDClientContext;
  PUCHAR              DataBufferVirtualAddress;
  DMA_LOGICAL_ADDRESS DataBufferDmaLogicalAddress;
  ULONG               DataBufferSize;
  USHORT              PDClientContextSize;
  USHORT              Attributes;
  USHORT              Flags;
  USHORT              DataStart;
  ULONG               DataLength;
  union {
    struct {
      union {
        ULONG64 RxFilterContext;
        ULONG64 GftFlowEntryId;
      };
      ULONG                         RxHashValue;
      union {
        struct {
          ULONG RxIPHeaderChecksumSucceeded : 1;
          ULONG RxTCPChecksumSucceeded : 1;
          ULONG RxUDPChecksumSucceeded : 1;
          ULONG RxIPHeaderChecksumFailed : 1;
          ULONG RxTCPChecksumFailed : 1;
          ULONG RxUDPChecksumFailed : 1;
          ULONG RxHashComputed : 1;
          ULONG RxHashWithL4PortNumbers : 1;
          ULONG RxGftDirectionIngress : 1;
          ULONG RxGftExceptionPacket : 1;
          ULONG RxGftCopyPacket : 1;
          ULONG RxGftSamplePacket : 1;
          ULONG RxReserved1 : 4;
          ULONG RxCoalescedSegCount : 16;
          ULONG RxRscTcpTimestampDelta;
        };
        ULONG RxOffloads[2];
      };
      union {
        struct {
          ULONG TxIsIPv4 : 1;
          ULONG TxIsIPv6 : 1;
          ULONG TxTransportHeaderOffset : 10;
          ULONG TxMSS : 20;
          ULONG TxComputeIPHeaderChecksum : 1;
          ULONG TxComputeTCPChecksum : 1;
          ULONG TxComputeUDPChecksum : 1;
          ULONG TxIsEncapsulatedPacket : 1;
          ULONG TxInnerPacketOffsetsValid : 1;
          ULONG TxReserved1 : 11;
          ULONG TxInnerFrameOffset : 8;
          ULONG TxInnerIpHeaderRelativeOffset : 6;
          ULONG TxInnerIsIPv6 : 1;
          ULONG TxInnerTcpOptionsPresent : 1;
        };
        ULONG TxOffloads[2];
      };
      PD_BUFFER_VIRTUAL_SUBNET_INFO VirtualSubnetInfo;
      PD_BUFFER_8021Q_INFO          Ieee8021qInfo;
      USHORT                        GftSourceVPortId;
      ULONG                         Reserved;
      UINT64                        ProviderScratch;
    } MetaDataV0;
  };
} PD_BUFFER;