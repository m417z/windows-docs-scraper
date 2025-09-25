HRESULT OnLtxTransactionStart(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] GUID             guidLtx,
  [in] GUID             tsid,
  [in] BOOL             fRoot,
  [in] int              nIsolationLevel
);