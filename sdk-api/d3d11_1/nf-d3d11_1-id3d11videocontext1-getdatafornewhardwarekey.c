HRESULT GetDataForNewHardwareKey(
  [in]  ID3D11CryptoSession *pCryptoSession,
  [in]  UINT                PrivateInputSize,
  [in]  const void          *pPrivatInputData,
  [out] UINT64              *pPrivateOutputData
);