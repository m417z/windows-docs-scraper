HRESULT MFTEnum2(
  [in]           GUID                         guidCategory,
  [in]           UINT32                       Flags,
  [in]           const MFT_REGISTER_TYPE_INFO *pInputType,
  [in]           const MFT_REGISTER_TYPE_INFO *pOutputType,
  [in, optional] IMFAttributes                *pAttributes,
  [out]          IMFActivate                  ***pppMFTActivate,
  [out]          UINT32                       *pnumMFTActivate
);