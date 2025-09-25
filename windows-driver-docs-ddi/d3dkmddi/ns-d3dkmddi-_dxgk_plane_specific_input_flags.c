typedef struct _DXGK_PLANE_SPECIFIC_INPUT_FLAGS {
  union {
    struct {
      UINT Enabled : 1;
      UINT FlipImmediate : 1;
      UINT FlipOnNextVSync : 1;
      UINT SharedPrimaryTransition : 1;
      UINT IndependentFlipExclusive : 1;
      UINT FlipImmediateNoTearing : 1;
#if ...
      UINT Reserved : 26;
#else
      UINT Reserved : 27;
#endif
    };
    UINT Value;
  };
} DXGK_PLANE_SPECIFIC_INPUT_FLAGS;