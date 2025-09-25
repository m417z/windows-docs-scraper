NTSTRSAFEDDI RtlUnicodeStringPrintfEx(
  [out]           PUNICODE_STRING  DestinationString,
  [out, optional] PUNICODE_STRING  RemainingString,
  [in]            DWORD            dwFlags,
  [in]            NTSTRSAFE_PCWSTR pszFormat,
                  ...              
);