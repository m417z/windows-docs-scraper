VIDEOPORT_API VOID VideoPortAcquireSpinLock(
  [in, out] PVOID      HwDeviceExtension,
  [in]      PSPIN_LOCK SpinLock,
  [out]     PUCHAR     OldIrql
);