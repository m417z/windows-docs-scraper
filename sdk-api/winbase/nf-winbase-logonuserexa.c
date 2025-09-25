BOOL LogonUserExA(
  [in]            LPCSTR        lpszUsername,
  [in, optional]  LPCSTR        lpszDomain,
  [in, optional]  LPCSTR        lpszPassword,
  [in]            DWORD         dwLogonType,
  [in]            DWORD         dwLogonProvider,
  [out, optional] PHANDLE       phToken,
  [out, optional] PSID          *ppLogonSid,
  [out, optional] PVOID         *ppProfileBuffer,
  [out, optional] LPDWORD       pdwProfileLength,
  [out, optional] PQUOTA_LIMITS pQuotaLimits
);