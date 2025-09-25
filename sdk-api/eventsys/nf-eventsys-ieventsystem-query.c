HRESULT Query(
  [in]          BSTR     progID,
  [in]          BSTR     queryCriteria,
  [out]         int      *errorIndex,
  [out, retval] IUnknown **ppInterface
);