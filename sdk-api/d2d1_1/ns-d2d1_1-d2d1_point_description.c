typedef struct D2D1_POINT_DESCRIPTION {
  D2D1_POINT_2F point;
  D2D1_POINT_2F unitTangentVector;
  UINT32        endSegment;
  UINT32        endFigure;
  FLOAT         lengthToEndSegment;
} D2D1_POINT_DESCRIPTION;