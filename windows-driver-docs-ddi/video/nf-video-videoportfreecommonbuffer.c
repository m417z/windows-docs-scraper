VIDEOPORT_DEPRECATED VIDEOPORT_API VOID VideoPortFreeCommonBuffer(
  [in] IN PVOID            HwDeviceExtension,
  [in] IN ULONG            Length,
  [in] IN PVOID            VirtualAddress,
  [in] IN PHYSICAL_ADDRESS LogicalAddress,
  [in] IN BOOLEAN          CacheEnabled
);