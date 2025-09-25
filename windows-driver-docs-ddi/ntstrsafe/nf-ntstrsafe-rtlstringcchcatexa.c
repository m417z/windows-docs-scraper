NTSTRSAFEDDI RtlStringCchCatExA(
  [in, out, optional] NTSTRSAFE_PSTR  pszDest,
  [in]                size_t          cchDest,
  [in]                NTSTRSAFE_PCSTR pszSrc,
  [out, optional]     NTSTRSAFE_PSTR  *ppszDestEnd,
  [out, optional]     size_t          *pcchRemaining,
  [in]                DWORD           dwFlags
);