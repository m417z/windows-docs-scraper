NTSTRSAFEDDI RtlStringCchCopyNA(
  [out] NTSTRSAFE_PSTR pszDest,
  [in]  size_t         cchDest,
  [in]  STRSAFE_PCNZCH pszSrc,
        size_t         cchToCopy
);