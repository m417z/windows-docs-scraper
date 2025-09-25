NTSTRSAFEDDI RtlStringCbCatExA(
  [in, out, optional] NTSTRSAFE_PSTR  pszDest,
  [in]                size_t          cbDest,
  [in, optional]      NTSTRSAFE_PCSTR pszSrc,
  [out, optional]     NTSTRSAFE_PSTR  *ppszDestEnd,
  [out, optional]     size_t          *pcbRemaining,
  [in]                DWORD           dwFlags
);