WINSETUPAPI BOOL SetupIterateCabinetA(
  [in] PCSTR               CabinetFile,
  [in] DWORD               Reserved,
  [in] PSP_FILE_CALLBACK_A MsgHandler,
  [in] PVOID               Context
);