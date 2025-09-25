SCSIPORT_API VOID ScsiPortIoMapTransfer(
  [in] PVOID               HwDeviceExtension,
  [in] PSCSI_REQUEST_BLOCK Srb,
  [in] PVOID               LogicalAddress,
  [in] ULONG               Length
);