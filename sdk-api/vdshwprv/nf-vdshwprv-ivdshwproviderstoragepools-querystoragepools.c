HRESULT QueryStoragePools(
  [in]  ULONG               ulFlags,
  [in]  ULONGLONG           ullRemainingFreeSpace,
  [in]  VDS_POOL_ATTRIBUTES *pPoolAttributes,
  [out] IEnumVdsObject      **ppEnum
);