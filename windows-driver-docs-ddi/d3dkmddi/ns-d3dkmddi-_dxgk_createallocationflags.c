typedef struct _DXGK_CREATEALLOCATIONFLAGS {
  union {
    struct {
      UINT Resource : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_CREATEALLOCATIONFLAGS;