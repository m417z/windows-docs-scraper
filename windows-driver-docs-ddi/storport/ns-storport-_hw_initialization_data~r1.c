typedef struct _HW_INITIALIZATION_DATA {
  ULONG                       HwInitializationDataSize;
  INTERFACE_TYPE              AdapterInterfaceType;
  PHW_INITIALIZE              HwInitialize;
  PHW_STARTIO                 HwStartIo;
  PHW_INTERRUPT               HwInterrupt;
  PVOID                       HwFindAdapter;
  PHW_RESET_BUS               HwResetBus;
  PHW_DMA_STARTED             HwDmaStarted;
  PHW_ADAPTER_STATE           HwAdapterState;
  ULONG                       DeviceExtensionSize;
  ULONG                       SpecificLuExtensionSize;
  ULONG                       SrbExtensionSize;
  ULONG                       NumberOfAccessRanges;
  PVOID                       Reserved;
  UCHAR                       MapBuffers;
  BOOLEAN                     NeedPhysicalAddresses;
  BOOLEAN                     TaggedQueuing;
  BOOLEAN                     AutoRequestSense;
  BOOLEAN                     MultipleRequestPerLu;
  BOOLEAN                     ReceiveEvent;
  USHORT                      VendorIdLength;
  PVOID                       VendorId;
  union {
    USHORT ReservedUshort;
    USHORT PortVersionFlags;
  };
  USHORT                      DeviceIdLength;
  PVOID                       DeviceId;
  union {
    PHW_ADAPTER_CONTROL      HwAdapterControl;
    PHW_NVME_ADAPTER_CONTROL HwNvmeAdapterControl;
  };
  PHW_BUILDIO                 HwBuildIo;
  PHW_FREE_ADAPTER_RESOURCES  HwFreeAdapterResources;
  PHW_PROCESS_SERVICE_REQUEST HwProcessServiceRequest;
  PHW_COMPLETE_SERVICE_IRP    HwCompleteServiceIrp;
  PHW_INITIALIZE_TRACING      HwInitializeTracing;
  PHW_CLEANUP_TRACING         HwCleanupTracing;
  PHW_TRACING_ENABLED         HwTracingEnabled;
  ULONG                       FeatureSupport;
  ULONG                       SrbTypeFlags;
  ULONG                       AddressTypeFlags;
  ULONG                       Reserved1;
  union {
    PHW_UNIT_CONTROL      HwUnitControl;
    PHW_NAMESPACE_CONTROL HwNamespaceControl;
  };
} HW_INITIALIZATION_DATA, *PHW_INITIALIZATION_DATA;