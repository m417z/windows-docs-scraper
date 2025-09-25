HRESULT AddSprites(
                 UINT32                  spriteCount,
  [in]           const D2D1_RECT_F       *destinationRectangles,
  [in, optional] const D2D1_RECT_U       *sourceRectangles,
  [in, optional] const D2D1_COLOR_F      *colors,
  [in, optional] const D2D1_MATRIX_3X2_F *transforms,
                 UINT32                  destinationRectanglesStride,
                 UINT32                  sourceRectanglesStride,
                 UINT32                  colorsStride,
                 UINT32                  transformsStride
);