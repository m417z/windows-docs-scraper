typedef struct _BOOTDISK_INFORMATION_EX {
  LONGLONG BootPartitionOffset;
  LONGLONG SystemPartitionOffset;
  ULONG    BootDeviceSignature;
  ULONG    SystemDeviceSignature;
  GUID     BootDeviceGuid;
  GUID     SystemDeviceGuid;
  BOOLEAN  BootDeviceIsGpt;
  BOOLEAN  SystemDeviceIsGpt;
} BOOTDISK_INFORMATION_EX, *PBOOTDISK_INFORMATION_EX;