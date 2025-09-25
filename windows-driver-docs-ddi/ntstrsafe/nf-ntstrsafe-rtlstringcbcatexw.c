NTSTRSAFEDDI RtlStringCbCatExW(
  [in, out, optional] NTSTRSAFE_PWSTR  pszDest,
  [in]                size_t           cbDest,
  [in, optional]      NTSTRSAFE_PCWSTR pszSrc,
  [out, optional]     NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional]     size_t           *pcbRemaining,
  [in]                DWORD            dwFlags
);