SCSIPORT_API VOID ScsiPortLogError(
  PVOID               HwDeviceExtension,
  PSCSI_REQUEST_BLOCK Srb,
  UCHAR               PathId,
  UCHAR               TargetId,
  UCHAR               Lun,
  ULONG               ErrorCode,
  ULONG               UniqueId
);