NTSYSAPI NTSTATUS RtlUnicodeToUTF8N(
  [out] PCHAR  UTF8StringDestination,
  [in]  ULONG  UTF8StringMaxByteCount,
  [out] PULONG UTF8StringActualByteCount,
  [in]  PCWCH  UnicodeStringSource,
  [in]  ULONG  UnicodeStringByteCount
);