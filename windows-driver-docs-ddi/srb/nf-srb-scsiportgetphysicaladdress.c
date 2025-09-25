SCSIPORT_API SCSI_PHYSICAL_ADDRESS ScsiPortGetPhysicalAddress(
  [in]  PVOID               HwDeviceExtension,
  [in]  PSCSI_REQUEST_BLOCK Srb,
  [in]  PVOID               VirtualAddress,
  [out] ULONG               *Length
);