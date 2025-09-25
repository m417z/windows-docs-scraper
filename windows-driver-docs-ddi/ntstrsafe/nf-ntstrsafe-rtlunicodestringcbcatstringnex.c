NTSTRSAFEDDI RtlUnicodeStringCbCatStringNEx(
  [in, out]       PUNICODE_STRING  DestinationString,
  [in]            NTSTRSAFE_PCWSTR pszSrc,
  [in]            size_t           cbToAppend,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);