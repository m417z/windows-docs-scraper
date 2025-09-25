NTSTATUS RtlConvertSidToUnicodeString(
  [out] PUNICODE_STRING UnicodeString,
  [in]  PSID            Sid,
  [in]  BOOLEAN         AllocateDestinationString
);