INT GetServiceA(
  [in]           DWORD                dwNameSpace,
  [in]           LPGUID               lpGuid,
  [in]           LPSTR                lpServiceName,
  [in]           DWORD                dwProperties,
  [out]          LPVOID               lpBuffer,
  [in, out]      LPDWORD              lpdwBufferSize,
  [in, optional] LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
);