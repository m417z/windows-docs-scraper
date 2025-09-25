NTSYSAPI NTSTATUS RtlUpcaseUnicodeToCustomCPN(
  PCPTABLEINFO CustomCP,
  PCH          CustomCPString,
  ULONG        MaxBytesInCustomCPString,
  PULONG       BytesInCustomCPString,
  PWCH         UnicodeString,
  ULONG        BytesInUnicodeString
);