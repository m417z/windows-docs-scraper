ULONG StorPortGetDataInBufferMdl(
  [in]  PVOID               HwDeviceExtension,
  [in]  PSCSI_REQUEST_BLOCK Srb,
  [out] PVOID               *Mdl
);