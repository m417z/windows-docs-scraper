typedef struct _D3DKMT_PRESENT_DISPLAY_ONLY_FLAGS {
  union {
    struct {
      UINT Rotate : 1;
      UINT Reserved : 31;
    };
         UINT Value;
  };
} D3DKMT_PRESENT_DISPLAY_ONLY_FLAGS;