typedef struct _FAULT_INFORMATION_ARM64_FLAGS {
  ULONG WriteNotRead : 1;
  ULONG InstructionNotData : 1;
  ULONG Privileged : 1;
  ULONG FaultAddressValid : 1;
  ULONG Reserved : 28;
} FAULT_INFORMATION_ARM64_FLAGS, *PFAULT_INFORMATION_ARM64_FLAGS;