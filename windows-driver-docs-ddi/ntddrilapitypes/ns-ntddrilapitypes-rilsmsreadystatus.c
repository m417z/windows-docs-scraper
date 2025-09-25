typedef struct RILSMSREADYSTATUS {
  DWORD            cbSize;
  DWORD            dwParams;
  DWORD            dwExecutor;
  RILSMSREADYSTATE dwReadyState;
} RILSMSREADYSTATUS, *LPRILSMSREADYSTATUS;