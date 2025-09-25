HRESULT CreateSharedHandle(
  IInspectable              *pObject,
  const SECURITY_ATTRIBUTES *pSecurityAttributes,
  DWORD                     Access,
  HSTRING                   Name,
  HANDLE                    *pHandle
);