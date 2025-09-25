typedef struct {
  ULONGLONG LogPageCount;
  UCHAR     LogPageType;
  UCHAR     AvailableLogPageCount;
  UCHAR     Reserved0[2];
  ULONG     NameSpaceId;
  UCHAR     Reserved1[48];
} NVME_RESERVATION_NOTIFICATION_LOG, *PNVME_RESERVATION_NOTIFICATION_LOG;