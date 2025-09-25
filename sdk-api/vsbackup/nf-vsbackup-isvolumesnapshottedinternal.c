HRESULT IsVolumeSnapshottedInternal(
  [in]  VSS_PWSZ pwszVolumeName,
  [out] BOOL     *pbSnapshotsPresent,
  [out] LONG     *plSnapshotCapability
);