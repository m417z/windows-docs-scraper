typedef struct _STORAGE_HW_FIRMWARE_DOWNLOAD {
  ULONG     Version;
  ULONG     Size;
  ULONG     Flags;
  UCHAR     Slot;
  UCHAR     Reserved[3];
  ULONGLONG Offset;
  ULONGLONG BufferSize;
  UCHAR     ImageBuffer[ANYSIZE_ARRAY];
} STORAGE_HW_FIRMWARE_DOWNLOAD, *PSTORAGE_HW_FIRMWARE_DOWNLOAD;