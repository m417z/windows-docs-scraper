VOID HalExamineMBR(
  [in]  PDEVICE_OBJECT DeviceObject,
  [in]  ULONG          SectorSize,
  [in]  ULONG          MBRTypeIdentifier,
  [out] PVOID          *Buffer
);