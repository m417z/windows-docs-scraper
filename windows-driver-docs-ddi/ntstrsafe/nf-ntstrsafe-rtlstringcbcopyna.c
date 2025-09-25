NTSTRSAFEDDI RtlStringCbCopyNA(
  [out] NTSTRSAFE_PSTR pszDest,
  [in]  size_t         cbDest,
  [in]  STRSAFE_PCNZCH pszSrc,
        size_t         cbToCopy
);