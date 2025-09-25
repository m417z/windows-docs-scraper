HRESULT WTSSBX_GetUserExternalSession(
  [in]  WCHAR                       *UserName,
  [in]  WCHAR                       *DomainName,
  [in]  WCHAR                       *ApplicationType,
  [in]  WTSSBX_IP_ADDRESS           *RedirectorInternalIP,
  [out] DWORD                       *pSessionId,
  [out] WTSSBX_MACHINE_CONNECT_INFO *pMachineConnectInfo
);