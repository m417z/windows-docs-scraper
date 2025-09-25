typedef struct _DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS {
  union {
    struct {
      UINT FlipConvertedToImmediate : 1;
      UINT PostPresentNeeded : 1;
      UINT HsyncInterruptCompletion : 1;
#if ...
      UINT Reserved : 29;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS;