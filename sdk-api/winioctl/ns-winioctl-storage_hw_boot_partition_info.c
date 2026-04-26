typedef struct _STORAGE_HW_BOOT_PARTITION_INFO {
  DWORD     Version;
  DWORD     Size;
  DWORDLONG BPSZ;
  DWORD     Flags;
  DWORD     ImagePayloadAlignment;
  DWORD     ImagePayloadMaxSize;
  BYTE      SlotCount;
  BYTE      ABPID;
} STORAGE_HW_BOOT_PARTITION_INFO, *PSTORAGE_HW_BOOT_PARTITION_INFO;