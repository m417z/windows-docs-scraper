HRESULT CreateSharedHandle(
  [in, optional] const SECURITY_ATTRIBUTES *pAttributes,
                 DWORD                     dwAccess,
  [in, optional] LPCWSTR                   lpName,
  [out]          HANDLE                    *pHandle
);