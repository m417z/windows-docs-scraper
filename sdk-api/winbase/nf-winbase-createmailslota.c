HANDLE CreateMailslotA(
  [in]           LPCSTR                lpName,
  [in]           DWORD                 nMaxMessageSize,
  [in]           DWORD                 lReadTimeout,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);