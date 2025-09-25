typedef struct _DXGK_CLOSENATIVEFENCE_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGK_CLOSENATIVEFENCE_FLAGS;