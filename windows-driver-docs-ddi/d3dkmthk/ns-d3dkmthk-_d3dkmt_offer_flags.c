typedef struct _D3DKMT_OFFER_FLAGS {
  union {
    struct {
      UINT OfferImmediately : 1;
      UINT AllowDecommit : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DKMT_OFFER_FLAGS;