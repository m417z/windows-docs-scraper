NTSYSAPI NTSTATUS RtlUpcaseUnicodeString(
  [in, out] PUNICODE_STRING  DestinationString,
  [in]      PCUNICODE_STRING SourceString,
  [in]      BOOLEAN          AllocateDestinationString
);