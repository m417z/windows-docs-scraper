HRESULT CreateCompatibleRenderTarget(
  const D2D1_SIZE_F                     *desiredSize,
  const D2D1_SIZE_U                     *desiredPixelSize,
  const D2D1_PIXEL_FORMAT               *desiredFormat,
  D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options,
  ID2D1BitmapRenderTarget               **bitmapRenderTarget
);