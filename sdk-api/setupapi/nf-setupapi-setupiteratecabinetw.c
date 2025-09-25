WINSETUPAPI BOOL SetupIterateCabinetW(
  [in] PCWSTR              CabinetFile,
  [in] DWORD               Reserved,
  [in] PSP_FILE_CALLBACK_W MsgHandler,
  [in] PVOID               Context
);