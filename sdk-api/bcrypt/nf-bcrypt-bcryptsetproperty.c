NTSTATUS BCryptSetProperty(
  [in, out] BCRYPT_HANDLE hObject,
  [in]      LPCWSTR       pszProperty,
  [in]      PUCHAR        pbInput,
  [in]      ULONG         cbInput,
  [in]      ULONG         dwFlags
);