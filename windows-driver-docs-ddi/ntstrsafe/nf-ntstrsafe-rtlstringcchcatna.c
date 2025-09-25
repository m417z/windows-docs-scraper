NTSTRSAFEDDI RtlStringCchCatNA(
  [in, out] NTSTRSAFE_PSTR pszDest,
  [in]      size_t         cchDest,
  [in]      STRSAFE_PCNZCH pszSrc,
            size_t         cchToAppend
);