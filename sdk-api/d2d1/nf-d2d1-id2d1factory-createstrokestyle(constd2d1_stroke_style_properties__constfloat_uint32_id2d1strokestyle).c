HRESULT CreateStrokeStyle(
  [ref]          const D2D1_STROKE_STYLE_PROPERTIES & strokeStyleProperties,
  [in, optional] const FLOAT                          *dashes,
                 UINT32                               dashesCount,
  [out]          ID2D1StrokeStyle                     **strokeStyle
);