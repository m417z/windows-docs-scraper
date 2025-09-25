HRESULT QuerySessionBySessionId(
  [in]  BSTR         ProviderName,
  [in]  DWORD        dwSessionId,
  [in]  BSTR         TargetName,
  [out] ITsSbSession **ppSession
);