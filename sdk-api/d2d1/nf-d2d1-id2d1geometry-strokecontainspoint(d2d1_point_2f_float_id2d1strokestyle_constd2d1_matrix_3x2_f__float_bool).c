HRESULT StrokeContainsPoint(
  D2D1_POINT_2F             point,
  FLOAT                     strokeWidth,
  ID2D1StrokeStyle          *strokeStyle,
  const D2D1_MATRIX_3X2_F & worldTransform,
  FLOAT                     flatteningTolerance,
  BOOL                      *contains
);