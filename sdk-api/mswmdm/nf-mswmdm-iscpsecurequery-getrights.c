HRESULT GetRights(
  [in]      BYTE                *pData,
  [in]      DWORD               dwSize,
  [in]      BYTE                *pbSPSessionKey,
  [in]      DWORD               dwSessionKeyLen,
  [in]      IMDSPStorageGlobals *pStgGlobals,
  [out]     PWMDMRIGHTS         *ppRights,
  [out]     UINT                *pnRightsCount,
  [in, out] BYTE [8]            abMac
);