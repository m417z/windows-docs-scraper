typedef struct _DXGK_OPENALLOCATIONFLAGS {
  union {
    struct {
      UINT Create : 1;
      UINT ReadOnly : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_OPENALLOCATIONFLAGS;