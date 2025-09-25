ULONG StorPortGetOriginalMdl(
  [in]  PVOID               HwDeviceExtension,
  [in]  PSCSI_REQUEST_BLOCK Srb,
  [out] PVOID               *Mdl
);