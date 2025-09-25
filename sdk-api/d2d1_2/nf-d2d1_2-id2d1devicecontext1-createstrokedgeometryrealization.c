HRESULT CreateStrokedGeometryRealization(
  [in]           ID2D1Geometry            *geometry,
                 FLOAT                    flatteningTolerance,
                 FLOAT                    strokeWidth,
  [in, optional] ID2D1StrokeStyle         *strokeStyle,
  [out]          ID2D1GeometryRealization **geometryRealization
);