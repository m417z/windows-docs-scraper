struct XMMATRIX {
  union {
    XMVECTOR r[4];
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
    float    m[4][4];
  };
  XMVECTOR              r[4];
  void                  XMMATRIX();
  void                  XMMATRIX(
    const XMMATRIX & unnamedParam1
  );
  XMMATRIX &            operator=(
    const XMMATRIX & M
  ) noexcept;
  XMMATRIX &            operator=(
    const XMMATRIX & unnamedParam1
  );
  void                  XMMATRIX(
    XMMATRIX && unnamedParam1
  );
  XMMATRIX &            operator=(
    XMMATRIX && unnamedParam1
  );
  void                  XMMATRIX(
    FXMVECTOR R0,
    FXMVECTOR R1,
    FXMVECTOR R2,
    CXMVECTOR R3
  ) noexcept;
  void                  XMMATRIX(
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
  void                  XMMATRIX(
    const float *pArray
  ) noexcept;
  float                 operator()(
    size_t Row,
    size_t Column
  ) noexcept;
  float &               operator()(
    size_t Row,
    size_t Column
  ) noexcept;
  XMMATRIX              operator+() noexcept;
  XMMATRIX              operator-() noexcept;
  XMMATRIX &XM_CALLCONV operator+=(
    FXMMATRIX M
  ) noexcept;
  XMMATRIX &XM_CALLCONV operator-=(
    FXMMATRIX M
  ) noexcept;
  XMMATRIX &XM_CALLCONV operator*=(
    FXMMATRIX M
  ) noexcept;
  XMMATRIX &            operator*=(
    float S
  ) noexcept;
  XMMATRIX &            operator/=(
    float S
  ) noexcept;
  XMMATRIX XM_CALLCONV  operator+(
    FXMMATRIX M
  ) noexcept;
  XMMATRIX XM_CALLCONV  operator-(
    FXMMATRIX M
  ) noexcept;
  XMMATRIX XM_CALLCONV  operator*(
    FXMMATRIX M
  ) noexcept;
  XMMATRIX              operator*(
    float S
  ) noexcept;
  XMMATRIX              operator/(
    float S
  ) noexcept;
};