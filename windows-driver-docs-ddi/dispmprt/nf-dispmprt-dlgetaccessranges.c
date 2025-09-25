NTSTATUS DlGetAccessRanges(
  PVOID                   DeviceHandle,
  ULONG                   NumRequestedResources,
  PIO_RESOURCE_DESCRIPTOR RequestedResources,
  ULONG                   NumAccessRanges,
  PVIDEO_ACCESS_RANGE     AccessRanges,
  PVOID                   VendorId,
  PVOID                   DeviceId,
  PULONG                  Slot
);