NTSYSAPI NTSTATUS RtlUTF8ToUnicodeN(
  [out, optional] PWSTR  UnicodeStringDestination,
  [in]            ULONG  UnicodeStringMaxByteCount,
  [out]           PULONG UnicodeStringActualByteCount,
  [in]            PCCH   UTF8StringSource,
  [in]            ULONG  UTF8StringByteCount
);