typedef struct _DXGK_NOTIFYALLOCFLAGS {
  union {
    struct {
      UINT Eviction : 1;
      UINT IoMmuUnmap : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_NOTIFYALLOCFLAGS;