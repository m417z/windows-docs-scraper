NTSYSAPI NTSTATUS RtlUnicodeToMultiByteSize(
  [out] PULONG BytesInMultiByteString,
  [in]  PCWCH  UnicodeString,
  [in]  ULONG  BytesInUnicodeString
);