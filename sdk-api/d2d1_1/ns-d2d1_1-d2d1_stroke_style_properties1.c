typedef struct D2D1_STROKE_STYLE_PROPERTIES1 {
  D2D1_CAP_STYLE             startCap;
  D2D1_CAP_STYLE             endCap;
  D2D1_CAP_STYLE             dashCap;
  D2D1_LINE_JOIN             lineJoin;
  FLOAT                      miterLimit;
  D2D1_DASH_STYLE            dashStyle;
  FLOAT                      dashOffset;
  D2D1_STROKE_TRANSFORM_TYPE transformType;
} D2D1_STROKE_STYLE_PROPERTIES1;