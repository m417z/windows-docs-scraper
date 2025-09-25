NTSTRSAFEDDI RtlStringCchVPrintfW(
  [out] NTSTRSAFE_PWSTR  pszDest,
  [in]  size_t           cchDest,
  [in]  NTSTRSAFE_PCWSTR pszFormat,
  [in]  va_list          argList
);