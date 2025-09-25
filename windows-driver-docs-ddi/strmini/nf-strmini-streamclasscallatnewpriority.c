VOID STREAMAPI StreamClassCallAtNewPriority(
  [in, optional] PHW_STREAM_OBJECT    StreamObject,
  [in]           PVOID                HwDeviceExtension,
  [in]           STREAM_PRIORITY      Priority,
  [in]           PHW_PRIORITY_ROUTINE PriorityRoutine,
  [in]           PVOID                Context
);