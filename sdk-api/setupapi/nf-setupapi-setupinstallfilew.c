WINSETUPAPI BOOL SetupInstallFileW(
  [in] HINF                InfHandle,
  [in] PINFCONTEXT         InfContext,
  [in] PCWSTR              SourceFile,
  [in] PCWSTR              SourcePathRoot,
  [in] PCWSTR              DestinationName,
  [in] DWORD               CopyStyle,
  [in] PSP_FILE_CALLBACK_W CopyMsgHandler,
  [in] PVOID               Context
);