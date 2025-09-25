NTSTRSAFEDDI RtlStringCchCatNExA(
  [in, out, optional] NTSTRSAFE_PSTR pszDest,
  [in]                size_t         cchDest,
  [in, optional]      STRSAFE_PCNZCH pszSrc,
                      size_t         cchToAppend,
  [out, optional]     NTSTRSAFE_PSTR *ppszDestEnd,
  [out, optional]     size_t         *pcchRemaining,
  [in]                DWORD          dwFlags
);