STORPORT_API BOOLEAN StorPortSetDeviceQueueDepth(
  [in] PVOID HwDeviceExtension,
  [in] UCHAR PathId,
  [in] UCHAR TargetId,
  [in] UCHAR Lun,
  [in] ULONG Depth
);