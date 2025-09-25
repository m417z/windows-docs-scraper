HRESULT CombineWithGeometry(
  ID2D1Geometry               *inputGeometry,
  D2D1_COMBINE_MODE           combineMode,
  const D2D1_MATRIX_3X2_F &   inputGeometryTransform,
  FLOAT                       flatteningTolerance,
  ID2D1SimplifiedGeometrySink *geometrySink
);