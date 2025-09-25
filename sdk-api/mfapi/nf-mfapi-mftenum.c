HRESULT MFTEnum(
  [in]  GUID                   guidCategory,
  [in]  UINT32                 Flags,
  [in]  MFT_REGISTER_TYPE_INFO *pInputType,
  [in]  MFT_REGISTER_TYPE_INFO *pOutputType,
  [in]  IMFAttributes          *pAttributes,
  [out] CLSID                  **ppclsidMFT,
  [out] UINT32                 *pcMFTs
);