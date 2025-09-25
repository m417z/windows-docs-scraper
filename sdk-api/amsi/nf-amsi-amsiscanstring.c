HRESULT AmsiScanString(
  [in]           HAMSICONTEXT amsiContext,
  [in]           LPCWSTR      string,
  [in]           LPCWSTR      contentName,
  [in, optional] HAMSISESSION amsiSession,
  [out]          AMSI_RESULT  *result
);