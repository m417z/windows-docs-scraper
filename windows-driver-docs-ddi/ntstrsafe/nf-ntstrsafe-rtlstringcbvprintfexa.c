NTSTRSAFEDDI RtlStringCbVPrintfExA(
  [out, optional] NTSTRSAFE_PSTR  pszDest,
  [in]            size_t          cbDest,
  [out, optional] NTSTRSAFE_PSTR  *ppszDestEnd,
  [out, optional] size_t          *pcbRemaining,
  [in]            DWORD           dwFlags,
  [in, optional]  NTSTRSAFE_PCSTR pszFormat,
  [in]            va_list         argList
);