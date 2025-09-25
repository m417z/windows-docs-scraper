int WSCSetProviderInfo(
  [in]  LPGUID                 lpProviderId,
  [in]  WSC_PROVIDER_INFO_TYPE InfoType,
  [in]  PBYTE                  Info,
  [in]  size_t                 InfoSize,
  [in]  DWORD                  Flags,
  [out] LPINT                  lpErrno
);