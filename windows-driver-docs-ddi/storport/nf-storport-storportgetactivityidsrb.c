ULONG StorPortGetActivityIdSrb(
  [in]  PVOID               HwDeviceExtension,
  [in]  PSCSI_REQUEST_BLOCK Srb,
  [out] LPGUID              ActivityId
);