BOOL Toolhelp32ReadProcessMemory(
  [in]  DWORD   th32ProcessID,
  [in]  LPCVOID lpBaseAddress,
  [out] LPVOID  lpBuffer,
  [in]  SIZE_T  cbRead,
  [out] SIZE_T  *lpNumberOfBytesRead
);