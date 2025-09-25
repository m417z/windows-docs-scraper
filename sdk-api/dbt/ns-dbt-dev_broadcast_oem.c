typedef struct _DEV_BROADCAST_OEM {
  DWORD dbco_size;
  DWORD dbco_devicetype;
  DWORD dbco_reserved;
  DWORD dbco_identifier;
  DWORD dbco_suppfunc;
} DEV_BROADCAST_OEM;