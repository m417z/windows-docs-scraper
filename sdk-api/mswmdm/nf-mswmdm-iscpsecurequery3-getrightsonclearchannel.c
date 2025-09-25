HRESULT GetRightsOnClearChannel(
  [in]  BYTE                *pData,
  [in]  DWORD               dwSize,
  [in]  BYTE                *pbSPSessionKey,
  [in]  DWORD               dwSessionKeyLen,
  [in]  IMDSPStorageGlobals *pStgGlobals,
  [in]  IWMDMProgress3      *pProgressCallback,
  [out] PWMDMRIGHTS         *ppRights,
  [out] UINT                *pnRightsCount
);