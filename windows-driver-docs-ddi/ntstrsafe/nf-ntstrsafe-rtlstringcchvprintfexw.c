NTSTRSAFEDDI RtlStringCchVPrintfExW(
  [out]           NTSTRSAFE_PWSTR  pszDest,
  [in]            size_t           cchDest,
  [out, optional] NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional] size_t           *pcchRemaining,
  [in]            DWORD            dwFlags,
  [in, optional]  NTSTRSAFE_PCWSTR pszFormat,
  [in]            va_list          argList
);