typedef struct _ENUM_SERVICE_STATUSW {
  LPWSTR         lpServiceName;
  LPWSTR         lpDisplayName;
  SERVICE_STATUS ServiceStatus;
} ENUM_SERVICE_STATUSW, *LPENUM_SERVICE_STATUSW;