NTSYSAPI NTSTATUS RtlUpcaseUnicodeToMultiByteN(
  [out]           PCHAR  MultiByteString,
  [in]            ULONG  MaxBytesInMultiByteString,
  [out, optional] PULONG BytesInMultiByteString,
  [in]            PCWCH  UnicodeString,
  [in]            ULONG  BytesInUnicodeString
);