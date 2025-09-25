typedef struct _BOOTDISK_INFORMATION {
  LONGLONG BootPartitionOffset;
  LONGLONG SystemPartitionOffset;
  ULONG    BootDeviceSignature;
  ULONG    SystemDeviceSignature;
} BOOTDISK_INFORMATION, *PBOOTDISK_INFORMATION;