typedef struct D2D1_DRAWING_STATE_DESCRIPTION {
  D2D1_ANTIALIAS_MODE      antialiasMode;
  D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode;
  D2D1_TAG                 tag1;
  D2D1_TAG                 tag2;
  D2D1_MATRIX_3X2_F        transform;
} D2D1_DRAWING_STATE_DESCRIPTION;