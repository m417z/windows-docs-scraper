typedef struct _DXGK_CONNECTION_MONITOR_CONNECT_FLAGS {
  union {
    struct {
      UINT Usb4DisplayPortMonitor : 1;
      UINT DisplayMuxConnectionChange : 1;
#if ...
      UINT Reserved : 30;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} DXGK_CONNECTION_MONITOR_CONNECT_FLAGS;