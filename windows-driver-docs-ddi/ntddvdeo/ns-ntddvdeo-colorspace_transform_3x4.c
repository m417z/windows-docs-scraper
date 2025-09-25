typedef struct _COLORSPACE_TRANSFORM_3x4 {
  float          ColorMatrix3x4[3][4];
  float          ScalarMultiplier;
  GAMMA_RAMP_RGB LookupTable1D[4096];
} COLORSPACE_TRANSFORM_3x4, *PCOLORSPACE_TRANSFORM_3x4;