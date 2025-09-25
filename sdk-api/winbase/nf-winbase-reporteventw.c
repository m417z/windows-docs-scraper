BOOL ReportEventW(
  [in] HANDLE  hEventLog,
  [in] WORD    wType,
  [in] WORD    wCategory,
  [in] DWORD   dwEventID,
  [in] PSID    lpUserSid,
  [in] WORD    wNumStrings,
  [in] DWORD   dwDataSize,
  [in] LPCWSTR *lpStrings,
  [in] LPVOID  lpRawData
);