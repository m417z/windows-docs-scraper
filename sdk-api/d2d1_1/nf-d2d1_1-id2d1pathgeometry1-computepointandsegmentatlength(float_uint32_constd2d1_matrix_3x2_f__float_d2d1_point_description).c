HRESULT ComputePointAndSegmentAtLength(
        FLOAT                     length,
        UINT32                    startSegment,
  [ref] const D2D1_MATRIX_3X2_F & worldTransform,
        FLOAT                     flatteningTolerance,
  [out] D2D1_POINT_DESCRIPTION    *pointDescription
);