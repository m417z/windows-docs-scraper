NTSYSAPI NTSTATUS RtlUpcaseUnicodeStringToOemString(
       POEM_STRING      DestinationString,
  [in] PCUNICODE_STRING SourceString,
  [in] BOOLEAN          AllocateDestinationString
);