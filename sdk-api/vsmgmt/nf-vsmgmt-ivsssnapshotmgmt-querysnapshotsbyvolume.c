HRESULT QuerySnapshotsByVolume(
  [in]  VSS_PWSZ       pwszVolumeName,
  [in]  VSS_ID         ProviderId,
  [out] IVssEnumObject **ppEnum
);