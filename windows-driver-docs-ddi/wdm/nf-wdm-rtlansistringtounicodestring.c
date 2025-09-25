NTSYSAPI NTSTATUS RtlAnsiStringToUnicodeString(
  [in, out] PUNICODE_STRING DestinationString,
  [in]      PCANSI_STRING   SourceString,
  [in]      BOOLEAN         AllocateDestinationString
);