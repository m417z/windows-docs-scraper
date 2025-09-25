NTSTRSAFEDDI RtlUnicodeStringCopyStringEx(
  [out]           PUNICODE_STRING  DestinationString,
  [in]            NTSTRSAFE_PCWSTR pszSrc,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags
);