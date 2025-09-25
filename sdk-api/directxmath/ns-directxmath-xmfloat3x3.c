struct XMFLOAT3X3 {
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
    };
    float m[3][3];
  };
  void         XMFLOAT3X3();
  void         XMFLOAT3X3(
    const XMFLOAT3X3 & unnamedParam1
  );
  XMFLOAT3X3 & operator=(
    const XMFLOAT3X3 & unnamedParam1
  );
  void         XMFLOAT3X3(
    XMFLOAT3X3 && unnamedParam1
  );
  XMFLOAT3X3 & operator=(
    XMFLOAT3X3 && unnamedParam1
  );
  void         XMFLOAT3X3(
    float m00,
    float m01,
    float m02,
    float m10,
    float m11,
    float m12,
    float m20,
    float m21,
    float m22
  ) noexcept;
  void         XMFLOAT3X3(
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
    const XMFLOAT3X3 & unnamedParam1
  );
  auto         operator<=>(
    const XMFLOAT3X3 & unnamedParam1
  );
};