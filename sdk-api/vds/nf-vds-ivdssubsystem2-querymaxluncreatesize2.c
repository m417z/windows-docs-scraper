HRESULT QueryMaxLunCreateSize2(
  [in]  VDS_LUN_TYPE  type,
  [in]  VDS_OBJECT_ID *pDriveIdArray,
  [in]  LONG          lNumberOfDrives,
  [in]  VDS_HINTS2    *pHints2,
  [out] ULONGLONG     *pullMaxLunSize
);