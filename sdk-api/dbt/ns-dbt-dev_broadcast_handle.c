typedef struct _DEV_BROADCAST_HANDLE {
  DWORD      dbch_size;
  DWORD      dbch_devicetype;
  DWORD      dbch_reserved;
  HANDLE     dbch_handle;
  HDEVNOTIFY dbch_hdevnotify;
  GUID       dbch_eventguid;
  LONG       dbch_nameoffset;
  BYTE       dbch_data[1];
} DEV_BROADCAST_HANDLE, *PDEV_BROADCAST_HANDLE;