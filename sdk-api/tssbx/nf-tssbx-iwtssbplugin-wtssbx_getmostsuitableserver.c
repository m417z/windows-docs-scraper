HRESULT WTSSBX_GetMostSuitableServer(
  [in]      WCHAR *UserName,
  [in]      WCHAR *DomainName,
  [in]      WCHAR *ApplicationType,
  [in]      WCHAR *FarmName,
  [in, out] long  *pMachineId
);