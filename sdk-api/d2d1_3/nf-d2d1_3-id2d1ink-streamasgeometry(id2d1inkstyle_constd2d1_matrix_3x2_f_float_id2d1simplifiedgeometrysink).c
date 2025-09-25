HRESULT StreamAsGeometry(
  [in, optional] ID2D1InkStyle               *inkStyle,
  [in, optional] const D2D1_MATRIX_3X2_F     *worldTransform,
                 FLOAT                       flatteningTolerance,
  [in]           ID2D1SimplifiedGeometrySink *geometrySink
);