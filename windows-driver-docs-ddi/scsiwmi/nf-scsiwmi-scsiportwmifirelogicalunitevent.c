VOID ScsiPortWmiFireLogicalUnitEvent(
  [in] PVOID  HwDeviceExtension,
  [in] UCHAR  PathId,
  [in] UCHAR  TargetId,
  [in] UCHAR  Lun,
  [in] LPGUID Guid,
  [in] ULONG  InstanceIndex,
  [in] ULONG  EventDataSize,
  [in] PVOID  EventData
);