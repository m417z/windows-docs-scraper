PCCERT_CONTEXT CryptUIDlgSelectCertificateFromStore(
  [in]           HCERTSTORE hCertStore,
  [in]           HWND       hwnd,
  [in, optional] LPCWSTR    pwszTitle,
  [in, optional] LPCWSTR    pwszDisplayString,
  [in]           DWORD      dwDontUseColumn,
  [in]           DWORD      dwFlags,
  [in]           void       *pvReserved
);