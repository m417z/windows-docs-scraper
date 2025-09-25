struct XMFLOAT3SE {
  union {
    struct {
      uint32_t xm : 9;
      uint32_t ym : 9;
      uint32_t zm : 9;
      uint32_t e : 5;
    };
      uint32_t v;
  };
  void         XMFLOAT3SE();
  void         XMFLOAT3SE(
    const XMFLOAT3SE & unnamedParam1
  );
  XMFLOAT3SE & operator=(
    const XMFLOAT3SE & unnamedParam1
  );
  void         XMFLOAT3SE(
    XMFLOAT3SE && unnamedParam1
  );
  XMFLOAT3SE & operator=(
    XMFLOAT3SE && unnamedParam1
  );
  void         XMFLOAT3SE(
    uint32_t Packed
  ) noexcept;
  void         XMFLOAT3SE(
    float _x,
    float _y,
    float _z
  ) noexcept;
  void         XMFLOAT3SE(
    const float *pArray
  ) noexcept;
  void         operator uint32_t() noexcept;
  XMFLOAT3SE & operator=(
    uint32_t Packed
  ) noexcept;
};