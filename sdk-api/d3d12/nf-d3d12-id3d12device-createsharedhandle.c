HRESULT CreateSharedHandle(
  [in]           ID3D12DeviceChild         *pObject,
  [in, optional] const SECURITY_ATTRIBUTES *pAttributes,
                 DWORD                     Access,
  [in, optional] LPCWSTR                   Name,
  [out]          HANDLE                    *pHandle
);