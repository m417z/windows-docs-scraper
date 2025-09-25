HRESULT SLInstallProofOfPurchase(
  [in]           HSLC   hSLC,
  [in]           PCWSTR pwszPKeyAlgorithm,
  [in]           PCWSTR pwszPKeyString,
  [in]           UINT   cbPKeySpecificData,
  [in, optional] PBYTE  pbPKeySpecificData,
  [out]          SLID   *pPkeyId
);