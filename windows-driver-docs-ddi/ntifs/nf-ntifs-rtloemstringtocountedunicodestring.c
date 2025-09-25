NTSYSAPI NTSTATUS RtlOemStringToCountedUnicodeString(
       PUNICODE_STRING DestinationString,
  [in] PCOEM_STRING    SourceString,
  [in] BOOLEAN         AllocateDestinationString
);