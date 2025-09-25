typedef struct _DXGK_MULTIPLANE_OVERLAY_BLEND {
  union {
    struct {
      UINT AlphaBlend : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_MULTIPLANE_OVERLAY_BLEND;