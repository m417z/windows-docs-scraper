struct XMFLOAT4X4 {
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
      float _41;
      float _42;
      float _43;
      float _44;
    };
    float m[4][4];
  };
  void         XMFLOAT4X4();
  void         XMFLOAT4X4(
    const XMFLOAT4X4 & unnamedParam1
  );
  XMFLOAT4X4 & operator=(
    const XMFLOAT4X4 & unnamedParam1
  );
  void         XMFLOAT4X4(
    XMFLOAT4X4 && unnamedParam1
  );
  XMFLOAT4X4 & operator=(
    XMFLOAT4X4 && unnamedParam1
  );
  void         XMFLOAT4X4(
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
    float m23,
    float m30,
    float m31,
    float m32,
    float m33
  ) noexcept;
  void         XMFLOAT4X4(
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
    const XMFLOAT4X4 & unnamedParam1
  );
  auto         operator<=>(
    const XMFLOAT4X4 & unnamedParam1
  );
};