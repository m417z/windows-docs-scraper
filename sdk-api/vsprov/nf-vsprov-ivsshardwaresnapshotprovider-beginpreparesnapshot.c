HRESULT BeginPrepareSnapshot(
  [in]      VSS_ID              SnapshotSetId,
  [in]      VSS_ID              SnapshotId,
  [in]      LONG                lContext,
  [in]      LONG                lLunCount,
  [in]      VSS_PWSZ            *rgDeviceNames,
  [in, out] VDS_LUN_INFORMATION *rgLunInformation
);