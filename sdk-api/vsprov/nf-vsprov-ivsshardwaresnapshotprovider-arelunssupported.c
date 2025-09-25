HRESULT AreLunsSupported(
  [in]      LONG                lLunCount,
  [in]      LONG                lContext,
  [in]      VSS_PWSZ            *rgwszDevices,
  [in, out] VDS_LUN_INFORMATION *pLunInformation,
  [out]     BOOL                *pbIsSupported
);