typedef struct _CMD_ENTRY {
  LPCWSTR            pwszCmdToken;
  PFN_HANDLE_CMD     pfnCmdHandler;
  DWORD              dwShortCmdHelpToken;
  DWORD              dwCmdHlpToken;
  DWORD              dwFlags;
  PNS_OSVERSIONCHECK pOsVersionCheck;
} CMD_ENTRY, *PCMD_ENTRY;