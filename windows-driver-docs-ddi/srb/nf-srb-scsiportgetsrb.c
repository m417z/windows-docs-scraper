SCSIPORT_API PSCSI_REQUEST_BLOCK ScsiPortGetSrb(
  [in] PVOID DeviceExtension,
  [in] UCHAR PathId,
  [in] UCHAR TargetId,
  [in] UCHAR Lun,
  [in] LONG  QueueTag
);