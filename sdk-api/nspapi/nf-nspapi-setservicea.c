INT SetServiceA(
  [in]           DWORD                dwNameSpace,
  [in]           DWORD                dwOperation,
  [in]           DWORD                dwFlags,
  [in]           LPSERVICE_INFOA      lpServiceInfo,
  [in, optional] LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
  [out]          LPDWORD              lpdwStatusFlags
);