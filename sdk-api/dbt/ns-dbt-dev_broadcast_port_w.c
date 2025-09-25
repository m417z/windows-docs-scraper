typedef struct _DEV_BROADCAST_PORT_W {
  DWORD   dbcp_size;
  DWORD   dbcp_devicetype;
  DWORD   dbcp_reserved;
  wchar_t dbcp_name[1];
} DEV_BROADCAST_PORT_W, *PDEV_BROADCAST_PORT_W;