INT GetAddressByNameW(
  [in]           DWORD                dwNameSpace,
  [in]           LPGUID               lpServiceType,
  [in, optional] LPWSTR               lpServiceName,
  [in, optional] LPINT                lpiProtocols,
  [in]           DWORD                dwResolution,
  [in, optional] LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
  [out]          LPVOID               lpCsaddrBuffer,
  [in, out]      LPDWORD              lpdwBufferLength,
  [in, out]      LPWSTR               lpAliasBuffer,
  [in, out]      LPDWORD              lpdwAliasBufferLength
);