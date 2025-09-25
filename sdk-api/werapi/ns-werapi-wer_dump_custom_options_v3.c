typedef struct _WER_DUMP_CUSTOM_OPTIONS_V3 {
  DWORD  dwSize;
  DWORD  dwMask;
  DWORD  dwDumpFlags;
  BOOL   bOnlyThisThread;
  DWORD  dwExceptionThreadFlags;
  DWORD  dwOtherThreadFlags;
  DWORD  dwExceptionThreadExFlags;
  DWORD  dwOtherThreadExFlags;
  DWORD  dwPreferredModuleFlags;
  DWORD  dwOtherModuleFlags;
  WCHAR  wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER];
  DWORD  dwPreferredModuleResetFlags;
  DWORD  dwOtherModuleResetFlags;
  PVOID  pvDumpKey;
  HANDLE hSnapshot;
  DWORD  dwThreadID;
} WER_DUMP_CUSTOM_OPTIONS_V3, *PWER_DUMP_CUSTOM_OPTIONS_V3;