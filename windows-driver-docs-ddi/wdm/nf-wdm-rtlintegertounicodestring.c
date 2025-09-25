NTSYSAPI NTSTATUS RtlIntegerToUnicodeString(
  [in]           ULONG           Value,
  [in, optional] ULONG           Base,
  [in, out]      PUNICODE_STRING String
);