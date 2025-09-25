typedef struct _DXGK_MULTIPLANE_OVERLAY_FLAGS {
  union {
    struct {
      UINT VerticalFlip : 1;
      UINT HorizontalFlip : 1;
      UINT StaticCheck : 1;
#if ...
      UINT Reserved : 29;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_MULTIPLANE_OVERLAY_FLAGS;