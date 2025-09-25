typedef struct _DHCP_SERVER_CONFIG_INFO_VQ {
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
  BOOL   QuarantineOn;
  DWORD  QuarDefFail;
  BOOL   QuarRuntimeStatus;
} DHCP_SERVER_CONFIG_INFO_VQ, *LPDHCP_SERVER_CONFIG_INFO_VQ;