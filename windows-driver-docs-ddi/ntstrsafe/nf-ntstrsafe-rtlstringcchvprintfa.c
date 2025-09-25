NTSTRSAFEDDI RtlStringCchVPrintfA(
  [out] NTSTRSAFE_PSTR  pszDest,
  [in]  size_t          cchDest,
  [in]  NTSTRSAFE_PCSTR pszFormat,
  [in]  va_list         argList
);