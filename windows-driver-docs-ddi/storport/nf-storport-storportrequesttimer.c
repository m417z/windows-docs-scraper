ULONG StorPortRequestTimer(
  [in]           PVOID        HwDeviceExtension,
  [in]           PVOID        TimerHandle,
  [in]           PHW_TIMER_EX TimerCallback,
  [in, optional] PVOID        CallbackContext,
  [in]           ULONGLONG    TimerValue,
  [in]           ULONGLONG    TolerableDelay
);