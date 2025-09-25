VIDEOPORT_DEPRECATED VIDEOPORT_API VP_STATUS VideoPortGetAccessRanges(
  PVOID                   HwDeviceExtension,
  ULONG                   NumRequestedResources,
  PIO_RESOURCE_DESCRIPTOR RequestedResources,
  ULONG                   NumAccessRanges,
  PVIDEO_ACCESS_RANGE     AccessRanges,
  PVOID                   VendorId,
  PVOID                   DeviceId,
  PULONG                  Slot
);