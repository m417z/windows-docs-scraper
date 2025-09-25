typedef struct _STORAGE_HW_FIRMWARE_INFO {
  ULONG                         Version;
  ULONG                         Size;
  UCHAR                         SupportUpgrade : 1;
  UCHAR                         Reserved0 : 7;
  UCHAR                         SlotCount;
  UCHAR                         ActiveSlot;
  UCHAR                         PendingActivateSlot;
  BOOLEAN                       FirmwareShared;
  UCHAR                         Reserved[3];
  ULONG                         ImagePayloadAlignment;
  ULONG                         ImagePayloadMaxSize;
  STORAGE_HW_FIRMWARE_SLOT_INFO Slot[ANYSIZE_ARRAY];
} STORAGE_HW_FIRMWARE_INFO, *PSTORAGE_HW_FIRMWARE_INFO;