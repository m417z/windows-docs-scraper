HRESULT MakeDecision(
  [in]      UINT                fuFlags,
  [in]      BYTE                *pData,
  [in]      DWORD               dwSize,
  [in]      DWORD               dwAppSec,
  [in]      BYTE                *pbSPSessionKey,
  [in]      DWORD               dwSessionKeyLen,
  [in]      IMDSPStorageGlobals *pStorageGlobals,
  [out]     ISCPSecureExchange  **ppExchange,
  [in, out] BYTE [8]            abMac
);