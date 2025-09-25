DWORD FormatMessageA(
  [in]           DWORD   dwFlags,
  [in, optional] LPCVOID lpSource,
  [in]           DWORD   dwMessageId,
  [in]           DWORD   dwLanguageId,
  [out]          LPSTR   lpBuffer,
  [in]           DWORD   nSize,
  [in, optional] va_list *Arguments
);