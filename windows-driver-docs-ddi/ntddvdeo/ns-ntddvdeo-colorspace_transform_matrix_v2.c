typedef struct _COLORSPACE_TRANSFORM_MATRIX_V2 {
  COLORSPACE_TRANSFORM_STAGE_CONTROL StageControlLookupTable1DDegamma;
  GAMMA_RAMP_RGB                     LookupTable1DDegamma[4096];
  COLORSPACE_TRANSFORM_STAGE_CONTROL StageControlColorMatrix3x3;
  float                              ColorMatrix3x3[3][3];
  COLORSPACE_TRANSFORM_STAGE_CONTROL StageControlLookupTable1DRegamma;
  GAMMA_RAMP_RGB                     LookupTable1DRegamma[4096];
} COLORSPACE_TRANSFORM_MATRIX_V2, *PCOLORSPACE_TRANSFORM_MATRIX_V2;