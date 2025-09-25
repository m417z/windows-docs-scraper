HRESULT MFTRegisterLocalByCLSID(
  [in] REFCLSID                     clisdMFT,
  [in] REFGUID                      guidCategory,
  [in] LPCWSTR                      pszName,
  [in] UINT32                       Flags,
  [in] UINT32                       cInputTypes,
  [in] const MFT_REGISTER_TYPE_INFO *pInputTypes,
  [in] UINT32                       cOutputTypes,
  [in] const MFT_REGISTER_TYPE_INFO *pOutputTypes
);