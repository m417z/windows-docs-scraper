BOOL LogonUserW(
  [in]           LPCWSTR lpszUsername,
  [in, optional] LPCWSTR lpszDomain,
  [in, optional] LPCWSTR lpszPassword,
  [in]           DWORD   dwLogonType,
  [in]           DWORD   dwLogonProvider,
  [out]          PHANDLE phToken
);