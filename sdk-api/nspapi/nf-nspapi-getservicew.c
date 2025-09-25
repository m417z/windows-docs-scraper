INT GetServiceW(
  [in]           DWORD                dwNameSpace,
  [in]           LPGUID               lpGuid,
  [in]           LPWSTR               lpServiceName,
  [in]           DWORD                dwProperties,
  [out]          LPVOID               lpBuffer,
  [in, out]      LPDWORD              lpdwBufferSize,
  [in, optional] LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
);