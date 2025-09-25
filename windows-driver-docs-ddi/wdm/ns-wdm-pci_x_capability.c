typedef struct {
  PCI_CAPABILITIES_HEADER Header;
  union {
    struct {
      USHORT DataParityErrorRecoveryEnable : 1;
      USHORT EnableRelaxedOrdering : 1;
      USHORT MaxMemoryReadByteCount : 2;
      USHORT MaxOutstandingSplitTransactions : 3;
      USHORT Reserved : 9;
    } bits;
    USHORT AsUSHORT;
  } Command;
  union {
    struct {
      ULONG FunctionNumber : 3;
      ULONG DeviceNumber : 5;
      ULONG BusNumber : 8;
      ULONG Device64Bit : 1;
      ULONG Capable133MHz : 1;
      ULONG SplitCompletionDiscarded : 1;
      ULONG UnexpectedSplitCompletion : 1;
      ULONG DeviceComplexity : 1;
      ULONG DesignedMaxMemoryReadByteCount : 2;
      ULONG DesignedMaxOutstandingSplitTransactions : 3;
      ULONG DesignedMaxCumulativeReadSize : 3;
      ULONG ReceivedSplitCompletionErrorMessage : 1;
      ULONG CapablePCIX266 : 1;
      ULONG CapablePCIX533 : 1;
    } bits;
    ULONG AsULONG;
  } Status;
} PCI_X_CAPABILITY, *PPCI_X_CAPABILITY;