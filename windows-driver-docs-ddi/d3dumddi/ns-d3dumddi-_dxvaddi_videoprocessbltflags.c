typedef struct _DXVADDI_VIDEOPROCESSBLTFLAGS {
  union {
    struct {
      UINT BackgroundChanged : 1;
      UINT TargetRectChanged : 1;
      UINT ColorDataChanged : 1;
      UINT AlphaChanged : 1;
      UINT Reserved : 12;
      UINT DestData : 16;
    };
    UINT Value;
  };
} DXVADDI_VIDEOPROCESSBLTFLAGS;