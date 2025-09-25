typedef struct _FAULT_INFORMATION_ARM64 {
  PVOID                         DomainHandle;
  PVOID                         FaultAddress;
  PDEVICE_OBJECT                PhysicalDeviceObject;
  ULONG                         InputMappingId;
  FAULT_INFORMATION_ARM64_FLAGS Flags;
  FAULT_INFORMATION_ARM64_TYPE  Type;
  ULONG64                       IommuBaseAddress;
} FAULT_INFORMATION_ARM64, *PFAULT_INFORMATION_ARM64;