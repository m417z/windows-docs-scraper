HRESULT CreateLun2(
  [in]  VDS_LUN_TYPE  type,
  [in]  ULONGLONG     ullSizeInBytes,
  [in]  VDS_OBJECT_ID *pDriveIdArray,
  [in]  LONG          lNumberOfDrives,
  [in]  LPWSTR        pwszUnmaskingList,
  [in]  VDS_HINTS2    *pHints2,
  [out] IVdsAsync     **ppAsync
);