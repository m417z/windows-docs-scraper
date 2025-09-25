typedef struct _MCI_STATUS_AMD_BITS {
  ULONG64 McaErrorCode : 16;
  ULONG64 ModelErrorCode : 16;
  ULONG64 ImplementationSpecific2 : 11;
  ULONG64 Poison : 1;
  ULONG64 Deferred : 1;
  ULONG64 ImplementationSpecific1 : 12;
  ULONG64 ContextCorrupt : 1;
  ULONG64 AddressValid : 1;
  ULONG64 MiscValid : 1;
  ULONG64 ErrorEnabled : 1;
  ULONG64 UncorrectedError : 1;
  ULONG64 StatusOverFlow : 1;
  ULONG64 Valid : 1;
} MCI_STATUS_AMD_BITS, *PMCI_STATUS_AMD_BITS;