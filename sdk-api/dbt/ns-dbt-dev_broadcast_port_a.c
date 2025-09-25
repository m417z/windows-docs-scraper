typedef struct _DEV_BROADCAST_PORT_A {
  DWORD dbcp_size;
  DWORD dbcp_devicetype;
  DWORD dbcp_reserved;
  char  dbcp_name[1];
} DEV_BROADCAST_PORT_A, *PDEV_BROADCAST_PORT_A;