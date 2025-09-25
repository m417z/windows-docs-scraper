typedef struct _DXGKARG_CREATEDOORBELL_FLAGS {
  union {
    struct {
      UINT ResizeRingBufferOperation : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGKARG_CREATEDOORBELL_FLAGS;