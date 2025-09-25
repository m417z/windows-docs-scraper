HRESULT TestAndSetServerState(
  [in]  BSTR         PoolName,
  [in]  BSTR         ServerFQDN,
  [in]  TARGET_STATE NewState,
  [in]  TARGET_STATE TestState,
  [out] TARGET_STATE *pInitState
);