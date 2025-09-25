NTSTRSAFEDDI RtlUnicodeStringCchCopyNEx(
  [out]           PUNICODE_STRING  DestinationString,
  [in]            PCUNICODE_STRING SourceString,
  [in]            size_t           cchToCopy,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);