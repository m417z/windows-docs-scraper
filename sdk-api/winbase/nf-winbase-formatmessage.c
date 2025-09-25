DWORD FormatMessage(
  [in]           DWORD   dwFlags,
  [in, optional] LPCVOID lpSource,
  [in]           DWORD   dwMessageId,
  [in]           DWORD   dwLanguageId,
  [out]          LPTSTR  lpBuffer,
  [in]           DWORD   nSize,
  [in, optional] va_list *Arguments
);