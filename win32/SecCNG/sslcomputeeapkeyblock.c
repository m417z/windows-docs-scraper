SECURITY_STATUS WINAPI SslComputeEapKeyBlock(
  _In_      NCRYPT_PROV_HANDLE hSslProvider,
  _In_      NCRYPT_KEY_HANDLE  hMasterKey,
  _In_      PBYTE              pbRandoms,
  _In_      DWORD              cbRandoms,
  _Out_opt_ PBYTE              pbOutput,
  _In_      DWORD              cbOutput,
  _Out_     DWORD              *pcbResult,
  _In_      DWORD              dwFlags
);