HRESULT SLInstallProofOfPurchaseEx(
  [in]           HSLC       hSLC,
  [in]           const SLID *pApplicationId,
  [in, optional] const SLID *pProductSkuId,
  [in]           PCWSTR     pwszPKeyAlgorithm,
  [in]           PCWSTR     pwszPKeyString,
  [in]           UINT       cbPKeySpecificData,
  [in, optional] PBYTE      pbPKeySpecificData,
  [out]          SLID       *pPkeyId
);