int WSCGetProviderInfo32(
  [in]      LPGUID                 lpProviderId,
  [in]      WSC_PROVIDER_INFO_TYPE InfoType,
  [out]     PBYTE                  Info,
  [in, out] size_t                 *InfoSize,
  [in]      DWORD                  Flags,
  [out]     LPINT                  lpErrno
);