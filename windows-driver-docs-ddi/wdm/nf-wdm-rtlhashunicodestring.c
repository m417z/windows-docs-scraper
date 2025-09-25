NTSYSAPI NTSTATUS RtlHashUnicodeString(
  [in]  PCUNICODE_STRING String,
  [in]  BOOLEAN          CaseInSensitive,
  [in]  ULONG            HashAlgorithm,
  [out] PULONG           HashValue
);