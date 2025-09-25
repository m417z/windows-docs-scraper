ENGAPI VOID EngUnicodeToMultiByteN(
  [out]           PCHAR  MultiByteString,
  [in]            ULONG  MaxBytesInMultiByteString,
  [out, optional] PULONG BytesInMultiByteString,
  [in]            PWSTR  UnicodeString,
  [in]            ULONG  BytesInUnicodeString
);