VOID STREAMAPI StreamClassScheduleTimer(
  [in, optional] PHW_STREAM_OBJECT StreamObject,
  [in]           PVOID             HwDeviceExtension,
  [in]           ULONG             NumberOfMicroseconds,
  [in]           PHW_TIMER_ROUTINE TimerRoutine,
  [in]           PVOID             Context
);