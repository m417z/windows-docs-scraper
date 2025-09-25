typedef struct _D3DKMT_CONNECT_DOORBELL_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} D3DKMT_CONNECT_DOORBELL_FLAGS;