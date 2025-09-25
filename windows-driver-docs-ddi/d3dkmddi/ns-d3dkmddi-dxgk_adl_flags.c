typedef struct _DXGK_ADL_FLAGS {
  union {
    struct {
      UINT32 Contiguous : 1;
      UINT32 Reserved : 31;
    };
    UINT32 Value;
  };
} DXGK_ADL_FLAGS;