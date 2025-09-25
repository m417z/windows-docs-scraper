HRESULT AddEnum(
  [in]  IWbemServices   *pNamespace,
  [in]  LPCWSTR         wszClassName,
  [in]  long            lFlags,
  [in]  IWbemContext    *pContext,
  [out] IWbemHiPerfEnum **ppEnum,
  [out] long            *plId
);