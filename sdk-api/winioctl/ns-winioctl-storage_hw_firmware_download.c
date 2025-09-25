typedef struct _STORAGE_HW_FIRMWARE_DOWNLOAD {
  DWORD     Version;
  DWORD     Size;
  DWORD     Flags;
  BYTE      Slot;
  BYTE      Reserved[3];
  DWORDLONG Offset;
  DWORDLONG BufferSize;
  BYTE      ImageBuffer[ANYSIZE_ARRAY];
} STORAGE_HW_FIRMWARE_DOWNLOAD, *PSTORAGE_HW_FIRMWARE_DOWNLOAD;