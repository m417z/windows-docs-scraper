HRESULT FormatPartition(
  [in]  ULONGLONG            ullOffset,
  [in]  VDS_FILE_SYSTEM_TYPE type,
  [in]  LPWSTR               pwszLabel,
  [in]  DWORD                dwUnitAllocationSize,
  [in]  BOOL                 bForce,
  [in]  BOOL                 bQuickFormat,
  [in]  BOOL                 bEnableCompression,
  [out] IVdsAsync            **ppAsync
);