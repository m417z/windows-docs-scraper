HRESULT GetCryptoSessionPrivateDataSize(
  [in]           const GUID *pCryptoType,
  [in, optional] const GUID *pDecoderProfile,
  [in]           const GUID *pKeyExchangeType,
  [out]          UINT       *pPrivateInputSize,
  [out]          UINT       *pPrivateOutputSize
);