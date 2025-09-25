HRESULT QueryMaxLunCreateSizeInStoragePool(
  [in]  VDS_LUN_TYPE  type,
  [in]  VDS_OBJECT_ID StoragePoolId,
  [in]  VDS_HINTS2    *pHints2,
  [out] ULONGLONG     *pullMaxLunSize
);