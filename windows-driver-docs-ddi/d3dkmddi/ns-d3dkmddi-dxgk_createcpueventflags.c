typedef struct _DXGK_CREATECPUEVENTFLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGK_CREATECPUEVENTFLAGS;