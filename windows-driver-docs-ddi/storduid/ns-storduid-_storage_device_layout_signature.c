typedef struct _STORAGE_DEVICE_LAYOUT_SIGNATURE {
  ULONG   Version;
  ULONG   Size;
  BOOLEAN Mbr;
  union {
    ULONG MbrSignature;
    GUID  GptDiskId;
  } DeviceSpecific;
} STORAGE_DEVICE_LAYOUT_SIGNATURE, *PSTORAGE_DEVICE_LAYOUT_SIGNATURE;