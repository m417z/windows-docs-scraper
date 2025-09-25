NTSTRSAFEDDI RtlUnicodeStringCchCatStringNEx(
  [in, out]       PUNICODE_STRING  DestinationString,
  [in]            NTSTRSAFE_PCWSTR pszSrc,
  [in]            size_t           cchToAppend,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);