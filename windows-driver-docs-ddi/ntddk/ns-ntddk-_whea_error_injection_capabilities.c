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
    ULONG IA64Corrected : 1;
    ULONG IA64Recoverable : 1;
    ULONG IA64Fatal : 1;
    ULONG IA64RecoverableCache : 1;
    ULONG IA64RecoverableRegFile : 1;
    ULONG Reserved : 15;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} WHEA_ERROR_INJECTION_CAPABILITIES, *PWHEA_ERROR_INJECTION_CAPABILITIES;