NTSYSAPI NTSTATUS RtlMultiByteToUnicodeSize(
  [out] PULONG     BytesInUnicodeString,
  [in]  const CHAR *MultiByteString,
  [in]  ULONG      BytesInMultiByteString
);