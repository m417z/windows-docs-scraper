typedef struct RILOPERATORINFO {
  DWORD                 cbSize;
  DWORD                 dwParams;
  DWORD                 dwIndex;
  RILOPERATORINFOSTATUS dwStatus;
  RILOPERATORNAMES      ronNames;
} RILOPERATORINFO, *LPRILOPERATORINFO;