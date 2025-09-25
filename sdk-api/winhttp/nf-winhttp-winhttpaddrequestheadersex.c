WINHTTPAPI DWORD WinHttpAddRequestHeadersEx(
  HINTERNET               hRequest,
  DWORD                   dwModifiers,
  ULONGLONG               ullFlags,
  ULONGLONG               ullExtra,
  DWORD                   cHeaders,
  WINHTTP_EXTENDED_HEADER *pHeaders
);