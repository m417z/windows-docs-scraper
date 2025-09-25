HRESULT SLGetPKeyId(
  [in]  HSLC       hSLC,
  [in]  PCWSTR     pwszPKeyAlgorithm,
  [in]  PCWSTR     pwszPKeyString,
  [in]  UINT       cbPKeySpecificData,
  [in]  const BYTE *pbPKeySpecificData,
  [out] SLID       *pPKeyId
);