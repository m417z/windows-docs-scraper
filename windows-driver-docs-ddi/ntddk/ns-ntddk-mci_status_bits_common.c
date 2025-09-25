typedef struct _MCI_STATUS_BITS_COMMON {
  ULONG64 McaErrorCode : 16;
  ULONG64 ModelErrorCode : 16;
  ULONG64 Reserved : 25;
  ULONG64 ContextCorrupt : 1;
  ULONG64 AddressValid : 1;
  ULONG64 MiscValid : 1;
  ULONG64 ErrorEnabled : 1;
  ULONG64 UncorrectedError : 1;
  ULONG64 StatusOverFlow : 1;
  ULONG64 Valid : 1;
} MCI_STATUS_BITS_COMMON, *PMCI_STATUS_BITS_COMMON;