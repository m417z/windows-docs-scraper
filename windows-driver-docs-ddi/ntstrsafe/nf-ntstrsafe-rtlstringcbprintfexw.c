NTSTRSAFEDDI RtlStringCbPrintfExW(
  [out, optional] NTSTRSAFE_PWSTR  pszDest,
  [in]            size_t           cbDest,
  [out, optional] NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional] size_t           *pcbRemaining,
  [in]            DWORD            dwFlags,
  [in, optional]  NTSTRSAFE_PCWSTR pszFormat,
                  ...              
);