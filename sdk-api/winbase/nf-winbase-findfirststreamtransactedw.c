HANDLE FindFirstStreamTransactedW(
  [in]  LPCWSTR            lpFileName,
  [in]  STREAM_INFO_LEVELS InfoLevel,
  [out] LPVOID             lpFindStreamData,
        DWORD              dwFlags,
  [in]  HANDLE             hTransaction
);