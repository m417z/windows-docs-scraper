NTSTRSAFEDDI RtlUnicodeStringCchCatNEx(
  [in, out]       PUNICODE_STRING  DestinationString,
  [in]            PCUNICODE_STRING SourceString,
  [in]            size_t           cchToAppend,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);