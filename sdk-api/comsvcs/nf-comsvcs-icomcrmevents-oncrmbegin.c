HRESULT OnCRMBegin(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] GUID             guidClerkCLSID,
  [in] GUID             guidActivity,
  [in] GUID             guidTx,
  [in] WCHAR [64]       szProgIdCompensator,
  [in] WCHAR [64]       szDescription
);