typedef struct _ENUM_SERVICE_STATUS_PROCESSA {
  LPSTR                  lpServiceName;
  LPSTR                  lpDisplayName;
  SERVICE_STATUS_PROCESS ServiceStatusProcess;
} ENUM_SERVICE_STATUS_PROCESSA, *LPENUM_SERVICE_STATUS_PROCESSA;