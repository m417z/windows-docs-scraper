WINSETUPAPI BOOL SetupScanFileQueueW(
  [in]  HSPFILEQ            FileQueue,
  [in]  DWORD               Flags,
  [in]  HWND                Window,
  [in]  PSP_FILE_CALLBACK_W CallbackRoutine,
  [in]  PVOID               CallbackContext,
  [out] PDWORD              Result
);