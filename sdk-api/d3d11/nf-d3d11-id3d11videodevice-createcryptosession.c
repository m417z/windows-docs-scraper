HRESULT CreateCryptoSession(
  [in]  const GUID          *pCryptoType,
  [in]  const GUID          *pDecoderProfile,
  [in]  const GUID          *pKeyExchangeType,
  [out] ID3D11CryptoSession **ppCryptoSession
);