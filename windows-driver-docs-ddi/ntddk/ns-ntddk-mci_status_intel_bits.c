typedef struct _MCI_STATUS_INTEL_BITS {
  ULONG64 McaErrorCode : 16;
  ULONG64 ModelErrorCode : 16;
  ULONG64 OtherInfo : 5;
  ULONG64 FirmwareUpdateError : 1;
  ULONG64 CorrectedErrorCount : 15;
  ULONG64 ThresholdErrorStatus : 2;
  ULONG64 ActionRequired : 1;
  ULONG64 Signalling : 1;
  ULONG64 ContextCorrupt : 1;
  ULONG64 AddressValid : 1;
  ULONG64 MiscValid : 1;
  ULONG64 ErrorEnabled : 1;
  ULONG64 UncorrectedError : 1;
  ULONG64 StatusOverFlow : 1;
  ULONG64 Valid : 1;
} MCI_STATUS_INTEL_BITS, *PMCI_STATUS_INTEL_BITS;