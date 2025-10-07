SECURITY_STATUS WINAPI SslHashHandshake(
  _In_    NCRYPT_PROV_HANDLE hSslProvider,
  _Inout_ NCRYPT_HASH_HANDLE hHandshakeHash,
  _Out_   PBYTE              pbInput,
  _In_    DWORD              cbInput,
  _In_    DWORD              dwFlags
);