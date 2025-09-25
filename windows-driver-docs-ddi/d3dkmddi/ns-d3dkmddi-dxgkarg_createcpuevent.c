typedef struct _DXGKARG_CREATECPUEVENT {
  HANDLE                   hKmdDevice;
  HANDLE                   hDxgCpuEvent;
  DXGK_CREATECPUEVENTFLAGS Flags;
  HANDLE                   hKmdCpuEvent;
} DXGKARG_CREATECPUEVENT;