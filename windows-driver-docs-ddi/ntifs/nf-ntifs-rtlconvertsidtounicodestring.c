NTSYSAPI NTSTATUS RtlConvertSidToUnicodeString(
  [in, out] PUNICODE_STRING UnicodeString,
  [in]      PSID            Sid,
  [in]      BOOLEAN         AllocateDestinationString
);