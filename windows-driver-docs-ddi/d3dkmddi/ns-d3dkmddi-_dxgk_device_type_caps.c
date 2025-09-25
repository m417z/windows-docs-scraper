typedef struct _DXGK_DEVICE_TYPE_CAPS {
  union {
    struct {
      UINT32 Discrete : 1;
      UINT32 Detachable : 1;
      UINT32 Reserved : 30;
    };
    UINT32 Value;
  };
} DXGK_DEVICE_TYPE_CAPS;