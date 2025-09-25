HRESULT CreateTransformedGeometry(
  ID2D1Geometry             *sourceGeometry,
  const D2D1_MATRIX_3X2_F & transform,
  ID2D1TransformedGeometry  **transformedGeometry
);