typedef struct _D3DKMT_PLANE_SPECIFIC_INPUT_FLAGS {
  union {
    struct {
      UINT Enabled : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DKMT_PLANE_SPECIFIC_INPUT_FLAGS;