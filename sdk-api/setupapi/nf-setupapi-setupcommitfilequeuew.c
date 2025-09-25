WINSETUPAPI BOOL SetupCommitFileQueueW(
  [in] HWND                Owner,
  [in] HSPFILEQ            QueueHandle,
  [in] PSP_FILE_CALLBACK_W MsgHandler,
  [in] PVOID               Context
);