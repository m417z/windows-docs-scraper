ULONG StorPortQueryPerformanceCounter(
  [in]            PVOID          HwDeviceExtension,
  [out, optional] PLARGE_INTEGER PerformanceFrequency,
  [out]           PLARGE_INTEGER PerformanceCounter
);