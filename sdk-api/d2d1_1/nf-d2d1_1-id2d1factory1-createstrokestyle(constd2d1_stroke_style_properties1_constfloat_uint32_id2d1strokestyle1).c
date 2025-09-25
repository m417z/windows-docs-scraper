HRESULT CreateStrokeStyle(
  [in]  const D2D1_STROKE_STYLE_PROPERTIES1 *strokeStyleProperties,
  [in]  const FLOAT                         *dashes,
        UINT32                              dashesCount,
  [out] ID2D1StrokeStyle1                   **strokeStyle
);