typedef struct _DEV_BROADCAST_VOLUME {
  DWORD dbcv_size;
  DWORD dbcv_devicetype;
  DWORD dbcv_reserved;
  DWORD dbcv_unitmask;
  WORD  dbcv_flags;
} DEV_BROADCAST_VOLUME;