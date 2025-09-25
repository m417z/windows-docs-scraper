pHalExamineMBR Phalexaminembr;

VOID Phalexaminembr(
  [in]  PDEVICE_OBJECT DeviceObject,
  [in]  ULONG SectorSize,
  [in]  ULONG MBRTypeIdentifier,
  [out] PVOID *Buffer
)
{...}