typedef struct _WNDOBJ {
  CLIPOBJ coClient;
  PVOID   pvConsumer;
  RECTL   rclClient;
  SURFOBJ *psoOwner;
} WNDOBJ, *PWNDOBJ;