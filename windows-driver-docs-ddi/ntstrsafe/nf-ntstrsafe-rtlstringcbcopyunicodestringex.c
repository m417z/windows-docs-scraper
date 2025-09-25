NTSTRSAFEDDI RtlStringCbCopyUnicodeStringEx(
  [out]           NTSTRSAFE_PWSTR  pszDest,
  [in]            size_t           cbDest,
  [in]            PCUNICODE_STRING SourceString,
  [out]           NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional] size_t           *pcbRemaining,
  [in]            DWORD            dwFlags
);