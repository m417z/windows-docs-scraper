NTSTRSAFEDDI RtlStringCbVPrintfW(
  [out] NTSTRSAFE_PWSTR  pszDest,
  [in]  size_t           cbDest,
  [in]  NTSTRSAFE_PCWSTR pszFormat,
  [in]  va_list          argList
);