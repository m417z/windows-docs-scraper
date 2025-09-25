typedef struct _D3DDDI_OVERLAYCOLORCONTROLSFLAGS {
  union {
    struct {
      UINT Brightness : 1;
      UINT Contrast : 1;
      UINT Hue : 1;
      UINT Saturation : 1;
      UINT Sharpness : 1;
      UINT Gamma : 1;
      UINT ColorEnable : 1;
      UINT Reserved : 25;
    };
    UINT Value;
  };
} D3DDDI_OVERLAYCOLORCONTROLSFLAGS;