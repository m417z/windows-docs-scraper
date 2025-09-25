STORPORT_API VOID StorPortLogError(
  [in]           PVOID               HwDeviceExtension,
  [in, optional] PSCSI_REQUEST_BLOCK Srb,
  [in]           UCHAR               PathId,
  [in]           UCHAR               TargetId,
  [in]           UCHAR               Lun,
  [in]           ULONG               ErrorCode,
  [in]           ULONG               UniqueId
);