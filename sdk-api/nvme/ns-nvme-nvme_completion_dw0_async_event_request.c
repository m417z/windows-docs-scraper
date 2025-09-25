typedef struct {
  ULONG AsyncEventType : 3;
  ULONG Reserved0 : 5;
  ULONG AsyncEventInfo : 8;
  ULONG LogPage : 8;
  ULONG Reserved1 : 8;
} NVME_COMPLETION_DW0_ASYNC_EVENT_REQUEST, *PNVME_COMPLETION_DW0_ASYNC_EVENT_REQUEST;