typedef struct _D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS {
  union {
    struct {
      UINT VerticalFlip : 1;
      UINT HorizontalFlip : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS;