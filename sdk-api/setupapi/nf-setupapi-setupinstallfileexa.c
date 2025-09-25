WINSETUPAPI BOOL SetupInstallFileExA(
  [in]  HINF                InfHandle,
  [in]  PINFCONTEXT         InfContext,
  [in]  PCSTR               SourceFile,
  [in]  PCSTR               SourcePathRoot,
  [in]  PCSTR               DestinationName,
  [in]  DWORD               CopyStyle,
  [in]  PSP_FILE_CALLBACK_A CopyMsgHandler,
  [in]  PVOID               Context,
  [out] PBOOL               FileWasInUse
);