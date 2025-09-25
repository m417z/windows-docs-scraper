typedef struct _DXGK_DESTROYALLOCATIONFLAGS {
  union {
    struct {
      UINT DestroyResource : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_DESTROYALLOCATIONFLAGS;