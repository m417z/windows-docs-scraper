SCSIPORT_API VOID ScsiPortCompleteRequest(
  [in] PVOID HwDeviceExtension,
  [in] UCHAR PathId,
  [in] UCHAR TargetId,
  [in] UCHAR Lun,
  [in] UCHAR SrbStatus
);