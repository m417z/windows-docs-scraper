NTSYSAPI NTSTATUS RtlUTF8StringToUnicodeString(
  PUNICODE_STRING DestinationString,
  PUTF8_STRING    SourceString,
  BOOLEAN         AllocateDestinationString
);