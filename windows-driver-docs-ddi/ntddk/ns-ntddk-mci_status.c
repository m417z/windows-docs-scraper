typedef union _MCI_STATUS {
  MCI_STATUS_BITS_COMMON CommonBits;
  MCI_STATUS_AMD_BITS    AmdBits;
  MCI_STATUS_INTEL_BITS  IntelBits;
  ULONG64                QuadPart;
} MCI_STATUS, *PMCI_STATUS;