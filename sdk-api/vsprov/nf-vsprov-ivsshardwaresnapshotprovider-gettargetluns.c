HRESULT GetTargetLuns(
  [in]      LONG                lLunCount,
  [in]      VSS_PWSZ            *rgDeviceNames,
  [in]      VDS_LUN_INFORMATION *rgSourceLuns,
  [in, out] VDS_LUN_INFORMATION *rgDestinationLuns
);