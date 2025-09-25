DWORD DavAddConnection(
  [in, out]      HANDLE  *ConnectionHandle,
  [in]           LPCWSTR RemoteName,
  [in, optional] LPCWSTR UserName,
  [in, optional] LPCWSTR Password,
  [in]           PBYTE   ClientCert,
  [in]           DWORD   CertSize
);