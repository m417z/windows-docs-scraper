typedef struct _HW_INITIALIZATION_DATA {
  union {
    ULONG HwInitializationDataSize;
    struct {
      USHORT SizeOfThisPacket;
      USHORT StreamClassVersion;
    };
  };
  ULONG                       HwInitializationDataSize;
  PHW_INTERRUPT               HwInterrupt;
  PHW_RECEIVE_DEVICE_SRB      HwReceivePacket;
  PHW_CANCEL_SRB              HwCancelPacket;
  PHW_REQUEST_TIMEOUT_HANDLER HwRequestTimeoutHandler;
  ULONG                       DeviceExtensionSize;
  ULONG                       PerRequestExtensionSize;
  ULONG                       PerStreamExtensionSize;
  ULONG                       FilterInstanceExtensionSize;
  BOOLEAN                     BusMasterDMA;
  BOOLEAN                     Dma24BitAddresses;
  ULONG                       BufferAlignment;
  BOOLEAN                     TurnOffSynchronization;
  ULONG                       DmaBufferSize;
  ULONG                       NumNameExtensions;
  PWCHAR                      *NameExtensionArray;
  ULONG                       Reserved[2];
} HW_INITIALIZATION_DATA, *PHW_INITIALIZATION_DATA;