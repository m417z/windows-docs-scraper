HRESULT ExposeSnapshot(
  [in]  VSS_ID   SnapshotId,
  [in]  VSS_PWSZ wszPathFromRoot,
  [in]  LONG     lAttributes,
  [in]  VSS_PWSZ wszExpose,
  [out] VSS_PWSZ *pwszExposed
);