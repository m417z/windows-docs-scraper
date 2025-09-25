typedef struct D2D1_RENDER_TARGET_PROPERTIES {
  D2D1_RENDER_TARGET_TYPE  type;
  D2D1_PIXEL_FORMAT        pixelFormat;
  FLOAT                    dpiX;
  FLOAT                    dpiY;
  D2D1_RENDER_TARGET_USAGE usage;
  D2D1_FEATURE_LEVEL       minLevel;
} D2D1_RENDER_TARGET_PROPERTIES;