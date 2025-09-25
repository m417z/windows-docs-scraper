struct XMFLOAT4X3 {
  union {
    struct {
      float _11;
      float _12;
      float _13;
      float _21;
      float _22;
      float _23;
      float _31;
      float _32;
      float _33;
      float _41;
      float _42;
      float _43;
    };
    float m[4][3];
    float f[12];
  };
  void         XMFLOAT4X3();
  void         XMFLOAT4X3(
    const XMFLOAT4X3 & unnamedParam1
  );
  XMFLOAT4X3 & operator=(
    const XMFLOAT4X3 & unnamedParam1
  );
  void         XMFLOAT4X3(
    XMFLOAT4X3 && unnamedParam1
  );
  XMFLOAT4X3 & operator=(
    XMFLOAT4X3 && unnamedParam1
  );
  void         XMFLOAT4X3(
    float m00,
    float m01,
    float m02,
    float m10,
    float m11,
    float m12,
    float m20,
    float m21,
    float m22,
    float m30,
    float m31,
    float m32
  ) noexcept;
  void         XMFLOAT4X3(
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
    const XMFLOAT4X3 & unnamedParam1
  );
  auto         operator<=>(
    const XMFLOAT4X3 & unnamedParam1
  );
};