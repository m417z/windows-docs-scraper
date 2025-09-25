WINSETUPAPI BOOL SetupCommitFileQueueA(
  [in] HWND                Owner,
  [in] HSPFILEQ            QueueHandle,
  [in] PSP_FILE_CALLBACK_A MsgHandler,
  [in] PVOID               Context
);