typedef struct _STORAGE_FIRMWARE_SLOT_INFO {
  UCHAR   SlotNumber;
  BOOLEAN ReadOnly;
  UCHAR   Reserved[6];
  union {
    UCHAR     Info[8];
    ULONGLONG AsUlonglong;
  } Revision;
} STORAGE_FIRMWARE_SLOT_INFO, *PSTORAGE_FIRMWARE_SLOT_INFO;