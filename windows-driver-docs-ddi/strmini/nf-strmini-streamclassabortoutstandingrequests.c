VOID StreamClassAbortOutstandingRequests(
  [in]           PVOID             HwDeviceExtension,
  [in, optional] PHW_STREAM_OBJECT HwStreamObject,
  [in]           NTSTATUS          Status
);