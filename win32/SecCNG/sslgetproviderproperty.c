SECURITY_STATUS WINAPI SslGetProviderProperty(
  _In_    NCRYPT_PROV_HANDLE hSslProvider,
  _In_    LPCWSTR            pszProperty,
  _Out_   PBYTE              ppbOutput,
  _Out_   DWORD              *pcbOutput,
  _Inout_ PVOID              *ppEnumState,
  _In_    DWORD              dwFlags
);