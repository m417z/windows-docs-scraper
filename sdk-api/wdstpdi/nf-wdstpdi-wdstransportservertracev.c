HRESULT WDSMCSAPI WdsTransportServerTraceV(
  [in] HANDLE          hProvider,
  [in] WDS_MC_SEVERITY Severity,
  [in] LPCWSTR         pwszFormat,
  [in] va_list         Params
);