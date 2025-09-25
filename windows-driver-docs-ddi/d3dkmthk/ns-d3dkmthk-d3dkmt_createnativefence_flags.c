typedef struct _D3DKMT_CREATENATIVEFENCE_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} D3DKMT_CREATENATIVEFENCE_FLAGS;