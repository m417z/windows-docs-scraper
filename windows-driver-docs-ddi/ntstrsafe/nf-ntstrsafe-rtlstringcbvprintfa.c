NTSTRSAFEDDI RtlStringCbVPrintfA(
  [out] NTSTRSAFE_PSTR  pszDest,
  [in]  size_t          cbDest,
  [in]  NTSTRSAFE_PCSTR pszFormat,
  [in]  va_list         argList
);