WINSETUPAPI VOID SetupWriteTextLog(
  [in] SP_LOG_TOKEN LogToken,
  [in] DWORD        Category,
  [in] DWORD        Flags,
  [in] PCSTR        MessageStr,
       ...          
);