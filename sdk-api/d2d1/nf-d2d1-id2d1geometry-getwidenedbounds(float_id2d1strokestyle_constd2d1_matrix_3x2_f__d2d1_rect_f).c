HRESULT GetWidenedBounds(
                 FLOAT                     strokeWidth,
  [in, optional] ID2D1StrokeStyle          *strokeStyle,
  [ref]          const D2D1_MATRIX_3X2_F & worldTransform,
  [out]          D2D1_RECT_F               *bounds
);