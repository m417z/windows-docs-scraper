DWORD MprAdminInterfaceGetHandle(
  [in]  MPR_SERVER_HANDLE hMprServer,
  [in]  LPWSTR            lpwsInterfaceName,
  [out] HANDLE            *phInterface,
  [in]  BOOL              fIncludeClientInterfaces
);