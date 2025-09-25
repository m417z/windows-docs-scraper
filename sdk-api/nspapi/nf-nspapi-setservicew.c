INT SetServiceW(
  [in]           DWORD                dwNameSpace,
  [in]           DWORD                dwOperation,
  [in]           DWORD                dwFlags,
  [in]           LPSERVICE_INFOW      lpServiceInfo,
  [in, optional] LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
  [out]          LPDWORD              lpdwStatusFlags
);