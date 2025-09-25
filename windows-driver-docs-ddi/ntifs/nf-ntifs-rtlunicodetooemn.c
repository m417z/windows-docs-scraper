NTSYSAPI NTSTATUS RtlUnicodeToOemN(
  [out]           PCHAR  OemString,
  [in]            ULONG  MaxBytesInOemString,
  [out, optional] PULONG BytesInOemString,
  [in]            PCWCH  UnicodeString,
  [in]            ULONG  BytesInUnicodeString
);