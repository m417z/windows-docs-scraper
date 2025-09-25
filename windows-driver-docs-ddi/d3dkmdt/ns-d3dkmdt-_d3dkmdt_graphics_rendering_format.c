typedef struct _D3DKMDT_GRAPHICS_RENDERING_FORMAT {
  D3DKMDT_2DREGION                PrimSurfSize;
  D3DKMDT_2DREGION                VisibleRegionSize;
  DWORD                           Stride;
  D3DDDIFORMAT                    PixelFormat;
  D3DKMDT_COLOR_BASIS             ColorBasis;
  D3DKMDT_PIXEL_VALUE_ACCESS_MODE PixelValueAccessMode;
} D3DKMDT_GRAPHICS_RENDERING_FORMAT;