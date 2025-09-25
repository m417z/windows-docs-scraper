HRESULT QueryMaxLunCreateSize(
  [in]  VDS_LUN_TYPE  type,
  [in]  VDS_OBJECT_ID *pDriveIdArray,
  [in]  LONG          lNumberOfDrives,
  [in]  VDS_HINTS     *pHints,
  [out] ULONGLONG     *pullMaxLunSize
);