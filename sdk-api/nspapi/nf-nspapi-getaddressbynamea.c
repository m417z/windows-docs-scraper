INT GetAddressByNameA(
  [in]           DWORD                dwNameSpace,
  [in]           LPGUID               lpServiceType,
  [in, optional] LPSTR                lpServiceName,
  [in, optional] LPINT                lpiProtocols,
  [in]           DWORD                dwResolution,
  [in, optional] LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
  [out]          LPVOID               lpCsaddrBuffer,
  [in, out]      LPDWORD              lpdwBufferLength,
  [in, out]      LPSTR                lpAliasBuffer,
  [in, out]      LPDWORD              lpdwAliasBufferLength
);