NTSTRSAFEDDI RtlUnicodeStringCatEx(
  [in, out]       PUNICODE_STRING  DestinationString,
  [in]            PCUNICODE_STRING SourceString,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);