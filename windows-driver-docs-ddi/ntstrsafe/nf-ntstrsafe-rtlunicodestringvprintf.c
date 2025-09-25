NTSTRSAFEDDI RtlUnicodeStringVPrintf(
  [out] PUNICODE_STRING  DestinationString,
  [in]  NTSTRSAFE_PCWSTR pszFormat,
  [in]  va_list          argList
);