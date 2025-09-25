NTSYSAPI NTSTATUS RtlUnicodeStringToUTF8String(
  PUTF8_STRING     DestinationString,
  PCUNICODE_STRING SourceString,
  BOOLEAN          AllocateDestinationString
);