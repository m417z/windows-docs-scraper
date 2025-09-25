NTSYSAPI NTSTATUS RtlInt64ToUnicodeString(
  [in]           ULONGLONG       Value,
  [in, optional] ULONG           Base,
  [in, out]      PUNICODE_STRING String
);