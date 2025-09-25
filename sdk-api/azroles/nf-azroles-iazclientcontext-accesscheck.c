HRESULT AccessCheck(
  [in]           BSTR    bstrObjectName,
  [in]           VARIANT varScopeNames,
  [in]           VARIANT varOperations,
  [in, optional] VARIANT varParameterNames,
  [in, optional] VARIANT varParameterValues,
  [in, optional] VARIANT varInterfaceNames,
  [in, optional] VARIANT varInterfaceFlags,
  [in, optional] VARIANT varInterfaces,
  [out]          VARIANT *pvarResults
);