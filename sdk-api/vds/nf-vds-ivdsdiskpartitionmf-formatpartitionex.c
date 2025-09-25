HRESULT FormatPartitionEx(
  [in]  ULONGLONG ullOffset,
  [in]  LPWSTR    pwszFileSystemTypeName,
  [in]  USHORT    usFileSystemRevision,
  [in]  ULONG     ulDesiredUnitAllocationSize,
  [in]  LPWSTR    pwszLabel,
  [in]  BOOL      bForce,
  [in]  BOOL      bQuickFormat,
  [in]  BOOL      bEnableCompression,
  [out] IVdsAsync **ppAsync
);