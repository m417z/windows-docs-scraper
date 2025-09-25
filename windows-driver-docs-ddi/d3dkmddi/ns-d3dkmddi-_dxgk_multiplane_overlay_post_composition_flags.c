typedef struct _DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS {
  union {
    struct {
      UINT VerticalFlip : 1;
      UINT HorizontalFlip : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS;