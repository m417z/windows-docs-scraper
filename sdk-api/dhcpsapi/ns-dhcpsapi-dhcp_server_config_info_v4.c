typedef struct _DHCP_SERVER_CONFIG_INFO_V4 {
  DWORD  APIProtocolSupport;
  LPWSTR DatabaseName;
  LPWSTR DatabasePath;
  LPWSTR BackupPath;
  DWORD  BackupInterval;
  DWORD  DatabaseLoggingFlag;
  DWORD  RestoreFlag;
  DWORD  DatabaseCleanupInterval;
  DWORD  DebugFlag;
  DWORD  dwPingRetries;
  DWORD  cbBootTableString;
  WCHAR  *wszBootTableString;
  BOOL   fAuditLog;
} DHCP_SERVER_CONFIG_INFO_V4, *LPDHCP_SERVER_CONFIG_INFO_V4;