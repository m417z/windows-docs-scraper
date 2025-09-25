NTSTRSAFEDDI RtlStringCchPrintfExA(
  [out, optional] NTSTRSAFE_PSTR  pszDest,
  [in]            size_t          cchDest,
  [out, optional] NTSTRSAFE_PSTR  *ppszDestEnd,
  [out, optional] size_t          *pcchRemaining,
  [in]            DWORD           dwFlags,
  [in]            NTSTRSAFE_PCSTR pszFormat,
                  ...             
);