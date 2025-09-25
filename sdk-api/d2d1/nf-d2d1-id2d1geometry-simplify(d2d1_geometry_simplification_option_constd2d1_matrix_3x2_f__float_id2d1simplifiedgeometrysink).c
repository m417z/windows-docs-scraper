HRESULT Simplify(
  D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption,
  const D2D1_MATRIX_3X2_F &           worldTransform,
  FLOAT                               flatteningTolerance,
  ID2D1SimplifiedGeometrySink         *geometrySink
);