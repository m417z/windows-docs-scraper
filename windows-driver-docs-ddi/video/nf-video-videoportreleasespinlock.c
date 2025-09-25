VIDEOPORT_API VOID VideoPortReleaseSpinLock(
  [in]      PVOID      HwDeviceExtension,
  [in, out] PSPIN_LOCK SpinLock,
  [in]      UCHAR      NewIrql
);