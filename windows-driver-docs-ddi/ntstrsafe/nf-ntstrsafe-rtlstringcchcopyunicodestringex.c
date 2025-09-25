NTSTRSAFEDDI RtlStringCchCopyUnicodeStringEx(
  [out]           NTSTRSAFE_PWSTR  pszDest,
  [in]            size_t           cchDest,
  [in]            PCUNICODE_STRING SourceString,
  [out]           NTSTRSAFE_PWSTR  *ppszDestEnd,
  [out, optional] size_t           *pcchRemaining,
  [in]            DWORD            dwFlags
);