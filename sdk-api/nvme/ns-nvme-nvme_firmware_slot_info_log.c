typedef struct {
  struct {
    UCHAR ActiveSlot : 3;
    UCHAR Reserved0 : 1;
    UCHAR PendingActivateSlot : 3;
    UCHAR Reserved1 : 1;
  } AFI;
  UCHAR     Reserved0[7];
  ULONGLONG FRS[7];
  UCHAR     Reserved1[448];
} NVME_FIRMWARE_SLOT_INFO_LOG, *PNVME_FIRMWARE_SLOT_INFO_LOG;