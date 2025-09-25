BOOL LogonUserA(
  [in]           LPCSTR  lpszUsername,
  [in, optional] LPCSTR  lpszDomain,
  [in, optional] LPCSTR  lpszPassword,
  [in]           DWORD   dwLogonType,
  [in]           DWORD   dwLogonProvider,
  [out]          PHANDLE phToken
);