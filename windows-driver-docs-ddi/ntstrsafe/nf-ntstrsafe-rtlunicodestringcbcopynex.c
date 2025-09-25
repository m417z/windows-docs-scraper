NTSTRSAFEDDI RtlUnicodeStringCbCopyNEx(
  [out]           PUNICODE_STRING  DestinationString,
  [in]            PCUNICODE_STRING SourceString,
  [in]            size_t           cbToCopy,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);