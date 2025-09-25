PFNPROCESSGROUPPOLICYEX Pfnprocessgrouppolicyex;

DWORD Pfnprocessgrouppolicyex(
  [in]  DWORD dwFlags,
  [in]  HANDLE hToken,
  [in]  HKEY hKeyRoot,
  [in]  PGROUP_POLICY_OBJECT pDeletedGPOList,
  [in]  PGROUP_POLICY_OBJECT pChangedGPOList,
  [in]  ASYNCCOMPLETIONHANDLE pHandle,
  [in]  BOOL *pbAbort,
  [in]  PFNSTATUSMESSAGECALLBACK pStatusCallback,
  [in]  IWbemServices *pWbemServices,
  [out] HRESULT *pRsopStatus
)
{...}