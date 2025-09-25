NTSYSAPI NTSTATUS RtlMultiByteToUnicodeN(
  [out]           PWCH       UnicodeString,
  [in]            ULONG      MaxBytesInUnicodeString,
  [out, optional] PULONG     BytesInUnicodeString,
  [in]            const CHAR *MultiByteString,
  [in]            ULONG      BytesInMultiByteString
);