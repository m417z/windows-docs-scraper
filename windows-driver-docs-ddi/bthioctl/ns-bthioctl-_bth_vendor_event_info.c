typedef struct _BTH_VENDOR_EVENT_INFO {
  BTH_ADDR BthAddress;
  ULONG    EventSize;
  UCHAR    EventInfo[1];
} BTH_VENDOR_EVENT_INFO, *PBTH_VENDOR_EVENT_INFO;