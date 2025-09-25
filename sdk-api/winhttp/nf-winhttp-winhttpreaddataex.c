WINHTTPAPI DWORD WinHttpReadDataEx(
  HINTERNET hRequest,
  LPVOID    lpBuffer,
  DWORD     dwNumberOfBytesToRead,
  LPDWORD   lpdwNumberOfBytesRead,
  ULONGLONG ullFlags,
  DWORD     cbProperty,
  PVOID     pvProperty
);