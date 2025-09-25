void FillOpacityMask(
  [in]  ID2D1Bitmap               *opacityMask,
  [in]  ID2D1Brush                *brush,
        D2D1_OPACITY_MASK_CONTENT content,
  [ref] const D2D1_RECT_F &       destinationRectangle,
  [ref] const D2D1_RECT_F &       sourceRectangle
);