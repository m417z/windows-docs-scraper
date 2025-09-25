NTSTRSAFEDDI RtlStringCbCatNW(
  [in, out] NTSTRSAFE_PWSTR pszDest,
  [in]      size_t          cbDest,
  [in]      STRSAFE_PCNZWCH pszSrc,
            size_t          cbToAppend
);