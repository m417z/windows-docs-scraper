NTSYSAPI NTSTATUS RtlOemToUnicodeN(
  [out]           PWCH   UnicodeString,
  [in]            ULONG  MaxBytesInUnicodeString,
  [out, optional] PULONG BytesInUnicodeString,
  [in]            PCCH   OemString,
  [in]            ULONG  BytesInOemString
);