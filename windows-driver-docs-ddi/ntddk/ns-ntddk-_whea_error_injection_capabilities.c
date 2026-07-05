typedef union _WHEA_ERROR_INJECTION_CAPABILITIES {
  struct {
    ULONG ProcessorCorrectable : 1;
    ULONG ProcessorUncorrectableNonFatal : 1;
    ULONG ProcessorUncorrectableFatal : 1;
    ULONG MemoryCorrectable : 1;
    ULONG MemoryUncorrectableNonFatal : 1;
    ULONG MemoryUncorrectableFatal : 1;
    ULONG PCIExpressCorrectable : 1;
    ULONG PCIExpressUncorrectableNonFatal : 1;
    ULONG PCIExpressUncorrectableFatal : 1;
    ULONG PlatformCorrectable : 1;
    ULONG PlatformUncorrectableNonFatal : 1;
    ULONG PlatformUncorrectableFatal : 1;
    ULONG CXLCacheProtocolCorrectable : 1;
    ULONG CXLCacheProtocolUncorrectableNonFatal : 1;
    ULONG CXLCacheProtocolUncorrectableFatal : 1;
    ULONG CXLMemProtocolCorrectable : 1;
    ULONG CXLMemProtocolUncorrectableNonFatal : 1;
    ULONG CXLMemProtocolUncorrectableFatal : 1;
    ULONG Reserved : 13;
    ULONG PlatformVendorDefined : 1;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} WHEA_ERROR_INJECTION_CAPABILITIES, *PWHEA_ERROR_INJECTION_CAPABILITIES;