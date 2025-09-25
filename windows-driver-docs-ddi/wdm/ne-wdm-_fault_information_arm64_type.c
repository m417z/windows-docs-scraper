typedef enum _FAULT_INFORMATION_ARM64_TYPE {
  UnsupportedUpstreamTransaction,
  AddressSizeFault,
  TlbMatchConflict,
  ExternalFault,
  PermissionFault,
  AccessFlagFault,
  TranslationFault,
  MaxFaultType
} FAULT_INFORMATION_ARM64_TYPE, *PFAULT_INFORMATION_ARM64_TYPE, FAULT_INFORMATION_X64_TYPE, *PFAULT_INFORMATION_X64_TYPE;