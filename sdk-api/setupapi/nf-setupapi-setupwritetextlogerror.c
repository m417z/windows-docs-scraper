WINSETUPAPI VOID SetupWriteTextLogError(
  [in] SP_LOG_TOKEN LogToken,
  [in] DWORD        Category,
  [in] DWORD        LogFlags,
  [in] DWORD        Error,
  [in] PCSTR        MessageStr,
       ...          
);