HRESULT CreateLun(
  [in]  VDS_LUN_TYPE  type,
  [in]  ULONGLONG     ullSizeInBytes,
  [in]  VDS_OBJECT_ID *pDriveIdArray,
  [in]  LONG          lNumberOfDrives,
  [in]  LPWSTR        pwszUnmaskingList,
  [in]  VDS_HINTS     *pHints,
  [out] IVdsAsync     **ppAsync
);