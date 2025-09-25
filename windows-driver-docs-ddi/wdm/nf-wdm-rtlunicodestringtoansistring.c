NTSYSAPI NTSTATUS RtlUnicodeStringToAnsiString(
  [in, out] PANSI_STRING     DestinationString,
  [in]      PCUNICODE_STRING SourceString,
  [in]      BOOLEAN          AllocateDestinationString
);