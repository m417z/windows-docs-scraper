NTSTRSAFEDDI RtlStringCchCopyNW(
  [out] NTSTRSAFE_PWSTR pszDest,
  [in]  size_t          cchDest,
  [in]  STRSAFE_PCNZWCH pszSrc,
        size_t          cchToCopy
);