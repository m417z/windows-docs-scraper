HRESULT FormatPartitionEx2(
  [in]  ULONGLONG ullOffset,
  [in]  LPWSTR    pwszFileSystemTypeName,
  [in]  USHORT    usFileSystemRevision,
  [in]  ULONG     ulDesiredUnitAllocationSize,
  [in]  LPWSTR    pwszLabel,
  [in]  DWORD     Options,
  [out] IVdsAsync **ppAsync
);