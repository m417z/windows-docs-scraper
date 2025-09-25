BOOL LogonUserExW(
  [in]            LPCWSTR       lpszUsername,
  [in, optional]  LPCWSTR       lpszDomain,
  [in, optional]  LPCWSTR       lpszPassword,
  [in]            DWORD         dwLogonType,
  [in]            DWORD         dwLogonProvider,
  [out, optional] PHANDLE       phToken,
  [out, optional] PSID          *ppLogonSid,
  [out, optional] PVOID         *ppProfileBuffer,
  [out, optional] LPDWORD       pdwProfileLength,
  [out, optional] PQUOTA_LIMITS pQuotaLimits
);