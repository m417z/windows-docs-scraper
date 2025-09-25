HRESULT CreateRefreshableEnum(
  [in]  IWbemServices   *pNamespace,
  [in]  LPCWSTR         wszClass,
  [in]  IWbemRefresher  *pRefresher,
  [in]  long            lFlags,
  [in]  IWbemContext    *pContext,
  [in]  IWbemHiPerfEnum *pHiPerfEnum,
  [out] long            *plId
);