typedef struct D3DDDI_OFFER_FLAGS {
  union {
    struct {
      UINT AllowDecommit : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DDDI_OFFER_FLAGS;