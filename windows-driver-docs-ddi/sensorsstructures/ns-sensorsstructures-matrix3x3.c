typedef struct {
  union {
    struct {
      float A11;
      float A12;
      float A13;
      float A21;
      float A22;
      float A23;
      float A31;
      float A32;
      float A33;
    };
    struct {
      VEC3D V1;
      VEC3D V2;
      VEC3D V3;
    };
    float M[3][3];
  };
} MATRIX3X3, *PMATRIX3X3;