NTSYSAPI NTSTATUS RtlUnicodeStringToInteger(
  [in]           PCUNICODE_STRING String,
  [in, optional] ULONG            Base,
  [out]          PULONG           Value
);