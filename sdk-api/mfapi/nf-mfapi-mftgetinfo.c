HRESULT MFTGetInfo(
  [in]  CLSID                  clsidMFT,
  [out] LPWSTR                 *pszName,
  [out] MFT_REGISTER_TYPE_INFO **ppInputTypes,
  [out] UINT32                 *pcInputTypes,
  [out] MFT_REGISTER_TYPE_INFO **ppOutputTypes,
  [out] UINT32                 *pcOutputTypes,
  [out] IMFAttributes          **ppAttributes
);