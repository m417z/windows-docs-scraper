typedef struct D2D1_ARC_SEGMENT {
  D2D1_POINT_2F        point;
  D2D1_SIZE_F          size;
  FLOAT                rotationAngle;
  D2D1_SWEEP_DIRECTION sweepDirection;
  D2D1_ARC_SIZE        arcSize;
} D2D1_ARC_SEGMENT;