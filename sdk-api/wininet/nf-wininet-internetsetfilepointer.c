DWORD InternetSetFilePointer(
  [in]      HINTERNET hFile,
  [in]      LONG      lDistanceToMove,
  [in, out] PLONG     lpDistanceToMoveHigh,
  [in]      DWORD     dwMoveMethod,
  [in]      DWORD_PTR dwContext
);