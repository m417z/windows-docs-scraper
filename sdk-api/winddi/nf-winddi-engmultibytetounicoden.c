ENGAPI VOID EngMultiByteToUnicodeN(
  [out]           LPWSTR UnicodeString,
  [in]            ULONG  MaxBytesInUnicodeString,
  [out, optional] PULONG BytesInUnicodeString,
  [in]            PCHAR  MultiByteString,
  [in]            ULONG  BytesInMultiByteString
);