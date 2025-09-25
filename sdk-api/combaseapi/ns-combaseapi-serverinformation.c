typedef struct tagServerInformation {
  DWORD  dwServerPid;
  DWORD  dwServerTid;
  UINT64 ui64ServerAddress;
} ServerInformation, *PServerInformation;