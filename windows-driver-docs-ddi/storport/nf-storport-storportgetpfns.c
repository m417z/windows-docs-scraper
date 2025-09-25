ULONG StorPortGetPfns(
  [in]  PVOID               HwDeviceExtension,
  [in]  PSCSI_REQUEST_BLOCK Srb,
  [in]  PVOID               Mdl,
  [out] PVOID               *Pfns,
  [out] ULONG               *PfnCount,
  [out] ULONG               *StartingOffset
);