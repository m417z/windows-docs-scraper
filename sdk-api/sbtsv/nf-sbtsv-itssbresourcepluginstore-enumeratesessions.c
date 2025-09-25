HRESULT EnumerateSessions(
  [in]      BSTR               targetName,
  [in]      BSTR               userName,
  [in]      BSTR               userDomain,
  [in]      BSTR               poolName,
  [in]      BSTR               initialProgram,
  [in]      TSSESSION_STATE    *pSessionState,
  [in, out] DWORD              *pdwCount,
  [out]     ITsSbSession ** [] ppVal
);