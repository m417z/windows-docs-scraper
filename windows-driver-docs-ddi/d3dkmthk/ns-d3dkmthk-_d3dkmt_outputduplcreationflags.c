typedef struct _D3DKMT_OUTPUTDUPLCREATIONFLAGS {
  union {
    struct {
      UINT CompositionUiCaptureOnly : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DKMT_OUTPUTDUPLCREATIONFLAGS;