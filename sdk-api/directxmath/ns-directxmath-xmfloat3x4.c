struct XMFLOAT3X4 {
  union {
    struct {
      float _11;
      float _12;
      float _13;
      float _14;
      float _21;
      float _22;
      float _23;
      float _24;
      float _31;
      float _32;
      float _33;
      float _34;
    };
    float m[3][4];
    float f[12];
  };
  void         XMFLOAT3X4();
  void         XMFLOAT3X4(
    const XMFLOAT3X4 & unnamedParam1
  );
  XMFLOAT3X4 & operator=(
    const XMFLOAT3X4 & unnamedParam1
  );
  void         XMFLOAT3X4(
    XMFLOAT3X4 && unnamedParam1
  );
  XMFLOAT3X4 & operator=(
    XMFLOAT3X4 && unnamedParam1
  );
  void         XMFLOAT3X4(
    float m00,
    float m01,
    float m02,
    float m03,
    float m10,
    float m11,
    float m12,
    float m13,
    float m20,
    float m21,
    float m22,
    float m23
  ) noexcept;
  void         XMFLOAT3X4(
    const float *pArray
  ) noexcept;
  float        operator()(
    size_t Row,
    size_t Column
  ) noexcept;
  float &      operator()(
    size_t Row,
    size_t Column
  ) noexcept;
  bool         operator==(
    const XMFLOAT3X4 & unnamedParam1
  );
  auto         operator<=>(
    const XMFLOAT3X4 & unnamedParam1
  );
};