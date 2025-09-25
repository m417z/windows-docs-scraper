NTSTRSAFEDDI RtlStringCbCatNExW(
  [in, out, optional] NTSTRSAFE_PWSTR pszDest,
  [in]                size_t          cbDest,
  [in, optional]      STRSAFE_PCNZWCH pszSrc,
                      size_t          cbToAppend,
  [out, optional]     NTSTRSAFE_PWSTR *ppszDestEnd,
  [out, optional]     size_t          *pcbRemaining,
  [in]                DWORD           dwFlags
);