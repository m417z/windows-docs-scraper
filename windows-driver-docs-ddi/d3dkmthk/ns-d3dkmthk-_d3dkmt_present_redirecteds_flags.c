typedef struct _D3DKMT_PRESENT_REDIRECTEDS_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} D3DKMT_PRESENT_REDIRECTED_FLAGS;