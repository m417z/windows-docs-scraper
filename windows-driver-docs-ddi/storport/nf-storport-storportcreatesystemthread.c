ULONG StorPortCreateSystemThread(
  [in]           PVOID                      HwDeviceExtension,
  [in]           PSTOR_THREAD_START_ROUTINE StartRoutine,
  [in/optional]  PVOID                      StartContext,
  [in/optional]  PSTOR_THREAD_PRIORITY      Priority,
  [out/optional] PVOID                      *ThreadContext
);