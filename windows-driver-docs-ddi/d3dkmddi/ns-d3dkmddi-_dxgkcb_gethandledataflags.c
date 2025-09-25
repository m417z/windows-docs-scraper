typedef struct _DXGKCB_GETHANDLEDATAFLAGS {
  union {
    struct {
      UINT DeviceSpecific : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGKCB_GETHANDLEDATAFLAGS;