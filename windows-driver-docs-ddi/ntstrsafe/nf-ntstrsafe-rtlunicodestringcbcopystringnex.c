NTSTRSAFEDDI RtlUnicodeStringCbCopyStringNEx(
  [out]           PUNICODE_STRING  DestinationString,
  [in]            NTSTRSAFE_PCWSTR pszSrc,
  [in]            size_t           cbToCopy,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);