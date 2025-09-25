HRESULT OnTransactionStart2(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] REFGUID          guidTx,
  [in] REFGUID          tsid,
  [in] BOOL             fRoot,
  [in] int              nIsolationLevel
);