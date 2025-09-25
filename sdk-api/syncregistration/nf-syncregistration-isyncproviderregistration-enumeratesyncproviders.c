HRESULT EnumerateSyncProviders(
  [in]  LPCGUID                pguidContentType,
  [in]  DWORD                  dwStateFlagsToFilterMask,
  [in]  DWORD                  dwStateFlagsToFilter,
  [in]  REFCLSID               refProviderClsId,
  [in]  DWORD                  dwSupportedArchitecture,
  [out] IEnumSyncProviderInfos **ppEnumSyncProviderInfos
);