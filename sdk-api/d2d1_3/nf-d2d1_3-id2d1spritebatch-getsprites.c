HRESULT GetSprites(
                  UINT32            startIndex,
                  UINT32            spriteCount,
  [out, optional] D2D1_RECT_F       *destinationRectangles,
  [out, optional] D2D1_RECT_U       *sourceRectangles,
  [out, optional] D2D1_COLOR_F      *colors,
  [out, optional] D2D1_MATRIX_3X2_F *transforms
);