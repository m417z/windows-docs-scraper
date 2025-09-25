HRESULT IsVolumeSnapshotted(
  [in]  VSS_PWSZ pwszVolumeName,
  [out] BOOL     *pbSnapshotsPresent,
  [out] LONG     *plSnapshotCompatibility
);