typedef struct _CMD_GROUP_ENTRY {
  LPCWSTR            pwszCmdGroupToken;
  DWORD              dwShortCmdHelpToken;
  ULONG              ulCmdGroupSize;
  DWORD              dwFlags;
  PCMD_ENTRY         pCmdGroup;
  PNS_OSVERSIONCHECK pOsVersionCheck;
} CMD_GROUP_ENTRY, *PCMD_GROUP_ENTRY;