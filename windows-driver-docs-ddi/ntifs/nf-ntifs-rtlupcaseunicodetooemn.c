NTSYSAPI NTSTATUS RtlUpcaseUnicodeToOemN(
  [out]           PCHAR  OemString,
  [in]            ULONG  MaxBytesInOemString,
  [out, optional] PULONG BytesInOemString,
  [in]            PCWCH  UnicodeString,
  [in]            ULONG  BytesInUnicodeString
);