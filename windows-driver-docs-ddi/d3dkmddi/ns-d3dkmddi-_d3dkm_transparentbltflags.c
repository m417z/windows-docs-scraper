typedef struct _D3DKM_TRANSPARENTBLTFLAGS {
  union {
    struct {
      UINT HonorAlpha : 1;
    };
    [in] UINT Value;
  };
} D3DKM_TRANSPARENTBLTFLAGS;