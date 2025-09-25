typedef struct _DHCP_SERVER_CONFIG_INFO {
  DWORD  APIProtocolSupport;
  LPWSTR DatabaseName;
  LPWSTR DatabasePath;
  LPWSTR BackupPath;
  DWORD  BackupInterval;
  DWORD  DatabaseLoggingFlag;
  DWORD  RestoreFlag;
  DWORD  DatabaseCleanupInterval;
  DWORD  DebugFlag;
} DHCP_SERVER_CONFIG_INFO, *LPDHCP_SERVER_CONFIG_INFO;