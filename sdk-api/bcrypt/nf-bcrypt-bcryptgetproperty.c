NTSTATUS BCryptGetProperty(
  [in]  BCRYPT_HANDLE hObject,
  [in]  LPCWSTR       pszProperty,
  [out] PUCHAR        pbOutput,
  [in]  ULONG         cbOutput,
  [out] ULONG         *pcbResult,
  [in]  ULONG         dwFlags
);