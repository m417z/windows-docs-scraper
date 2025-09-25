HRESULT CheckConsistency(
  [in, optional]  LPWSTR               wszWriterMetadata,
  [in, optional]  LPWSTR               wszComponentName,
  [in, optional]  LPWSTR               wszComponentLogicalPath,
  [in]            DWORD                cVolumes,
  [in, optional]  LPWSTR               *rgwszSourceVolumePath,
  [in, optional]  LPWSTR               *rgwszSnapshotVolumePath,
  [out, optional] IWsbApplicationAsync **ppAsync
);