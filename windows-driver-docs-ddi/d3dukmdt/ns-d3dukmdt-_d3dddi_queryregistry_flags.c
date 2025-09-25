typedef struct _D3DDDI_QUERYREGISTRY_FLAGS {
  union {
    struct {
      UINT TranslatePath : 1;
      UINT MutableValue : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_QUERYREGISTRY_FLAGS;