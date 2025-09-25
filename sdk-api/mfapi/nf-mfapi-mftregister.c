HRESULT MFTRegister(
  [in] CLSID                  clsidMFT,
  [in] GUID                   guidCategory,
  [in] LPWSTR                 pszName,
  [in] UINT32                 Flags,
  [in] UINT32                 cInputTypes,
  [in] MFT_REGISTER_TYPE_INFO *pInputTypes,
  [in] UINT32                 cOutputTypes,
  [in] MFT_REGISTER_TYPE_INFO *pOutputTypes,
  [in] IMFAttributes          *pAttributes
);