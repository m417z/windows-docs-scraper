typedef struct _D3DKMT_CREATE_DOORBELL_FLAGS {
  union {
    struct {
      UINT RequireSecondaryCpuVA : 1;
      UINT ResizeRingBufferOperation : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DKMT_CREATE_DOORBELL_FLAGS;