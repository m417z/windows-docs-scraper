typedef struct _WER_DUMP_CUSTOM_OPTIONS_V2 {
  DWORD dwSize;
  DWORD dwMask;
  DWORD dwDumpFlags;
  BOOL  bOnlyThisThread;
  DWORD dwExceptionThreadFlags;
  DWORD dwOtherThreadFlags;
  DWORD dwExceptionThreadExFlags;
  DWORD dwOtherThreadExFlags;
  DWORD dwPreferredModuleFlags;
  DWORD dwOtherModuleFlags;
  WCHAR wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER];
  DWORD dwPreferredModuleResetFlags;
  DWORD dwOtherModuleResetFlags;
} WER_DUMP_CUSTOM_OPTIONS_V2, *PWER_DUMP_CUSTOM_OPTIONS_V2;