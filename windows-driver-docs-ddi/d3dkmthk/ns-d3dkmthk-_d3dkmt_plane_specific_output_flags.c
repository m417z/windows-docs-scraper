typedef struct _D3DKMT_PLANE_SPECIFIC_OUTPUT_FLAGS {
  union {
    struct {
      UINT FlipConvertedToImmediate : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DKMT_PLANE_SPECIFIC_OUTPUT_FLAGS;