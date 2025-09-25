HRESULT FillInLunInfo(
  [in]      VSS_PWSZ            wszDeviceName,
  [in, out] VDS_LUN_INFORMATION *pLunInfo,
  [out]     BOOL                *pbIsSupported
);