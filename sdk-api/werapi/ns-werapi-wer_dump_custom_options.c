typedef struct _WER_DUMP_CUSTOM_OPTIONS {
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
} WER_DUMP_CUSTOM_OPTIONS, *PWER_DUMP_CUSTOM_OPTIONS;