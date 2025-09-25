typedef struct _ENUM_SERVICE_STATUS_PROCESSW {
  LPWSTR                 lpServiceName;
  LPWSTR                 lpDisplayName;
  SERVICE_STATUS_PROCESS ServiceStatusProcess;
} ENUM_SERVICE_STATUS_PROCESSW, *LPENUM_SERVICE_STATUS_PROCESSW;