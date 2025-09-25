NTSTRSAFEDDI RtlStringCchPrintfExW(
  [out, optional] NTSTRSAFE_PWSTR  pszDest,
  [in]            size_t           cchDest,
  [out, optional] NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional] size_t           *pcchRemaining,
  [in]            DWORD            dwFlags,
  [in]            NTSTRSAFE_PCWSTR pszFormat,
                  ...              
);