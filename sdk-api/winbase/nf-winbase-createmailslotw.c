HANDLE CreateMailslotW(
  [in]           LPCWSTR               lpName,
  [in]           DWORD                 nMaxMessageSize,
  [in]           DWORD                 lReadTimeout,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);