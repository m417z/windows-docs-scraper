NTSTRSAFEDDI RtlUnicodeStringCchCatStringN(
  [in, out] PUNICODE_STRING  DestinationString,
  [in]      NTSTRSAFE_PCWSTR pszSrc,
  [in]      size_t           cchToAppend
);