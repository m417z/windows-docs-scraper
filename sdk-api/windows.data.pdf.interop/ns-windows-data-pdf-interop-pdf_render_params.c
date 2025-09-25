typedef struct PDF_RENDER_PARAMS {
  D2D_RECT_F  SourceRect;
  UINT32      DestinationWidth;
  UINT32      DestinationHeight;
  D2D_COLOR_F BackgroundColor;
  BOOLEAN     IgnoreHighContrast;
} PDF_RENDER_PARAMS;