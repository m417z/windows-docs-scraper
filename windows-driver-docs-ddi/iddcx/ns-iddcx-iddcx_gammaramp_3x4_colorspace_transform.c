struct IDDCX_GAMMARAMP_3X4_COLORSPACE_TRANSFORM {
  BOOL      MatrixEnabled;
  float     ColorMatrix3x4[3][4];
  float     ScalarMultiplier;
  BOOL      LutEnabled;
  IDDCX_RGB LookupTable1D[4096];
};