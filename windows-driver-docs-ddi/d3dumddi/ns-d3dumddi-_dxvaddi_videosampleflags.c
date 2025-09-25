typedef struct _DXVADDI_VIDEOSAMPLEFLAGS {
  union {
    struct {
      UINT PaletteChanged : 1;
      UINT SrcRectChanged : 1;
      UINT DstRectChanged : 1;
      UINT ColorDataChanged : 1;
      UINT PlanarAlphaChanged : 1;
      UINT Reserved : 11;
      UINT SampleData : 16;
    };
    UINT Value;
  };
} DXVADDI_VIDEOSAMPLEFLAGS;