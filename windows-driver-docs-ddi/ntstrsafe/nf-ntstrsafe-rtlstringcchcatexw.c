NTSTRSAFEDDI RtlStringCchCatExW(
  [in, out, optional] NTSTRSAFE_PWSTR  pszDest,
  [in]                size_t           cchDest,
  [in]                NTSTRSAFE_PCWSTR pszSrc,
  [out, optional]     NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional]     size_t           *pcchRemaining,
  [in]                DWORD            dwFlags
);