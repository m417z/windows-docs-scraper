NTSTATUS RegisterOpRegionHandler(
  [in]  PDEVICE_OBJECT          DeviceObject,
  [in]  ULONG                   AccessType,
  [in]  ULONG                   RegionSpace,
  [in]  PACPI_OP_REGION_HANDLER Handler,
  [in]  PVOID                   Context,
  [in]  ULONG                   Flags,
  [out] PVOID                   *OperationRegionObject
);