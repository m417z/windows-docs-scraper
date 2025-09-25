NTSYSAPI NTSTATUS RtlUnicodeToCustomCPN(
  PCPTABLEINFO CustomCP,
  PCH          CustomCPString,
  ULONG        MaxBytesInCustomCPString,
  PULONG       BytesInCustomCPString,
  PWCH         UnicodeString,
  ULONG        BytesInUnicodeString
);