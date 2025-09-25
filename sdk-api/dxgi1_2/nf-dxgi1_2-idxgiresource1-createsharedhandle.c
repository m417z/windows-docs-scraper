HRESULT CreateSharedHandle(
  [in, optional] const SECURITY_ATTRIBUTES *pAttributes,
  [in]           DWORD                     dwAccess,
  [in, optional] LPCWSTR                   lpName,
  [out]          HANDLE                    *pHandle
);