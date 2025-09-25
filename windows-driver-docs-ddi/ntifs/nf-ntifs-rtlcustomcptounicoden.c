NTSYSAPI NTSTATUS RtlCustomCPToUnicodeN(
  PCPTABLEINFO CustomCP,
  PWCH         UnicodeString,
  ULONG        MaxBytesInUnicodeString,
  PULONG       BytesInUnicodeString,
  PCH          CustomCPString,
  ULONG        BytesInCustomCPString
);