struct XMFLOAT3PK {
  union {
    struct {
      uint32_t xm : 6;
      uint32_t xe : 5;
      uint32_t ym : 6;
      uint32_t ye : 5;
      uint32_t zm : 5;
      uint32_t ze : 5;
    };
      uint32_t v;
  };
  void         XMFLOAT3PK();
  void         XMFLOAT3PK(
    const XMFLOAT3PK & unnamedParam1
  );
  XMFLOAT3PK & operator=(
    const XMFLOAT3PK & unnamedParam1
  );
  void         XMFLOAT3PK(
    XMFLOAT3PK && unnamedParam1
  );
  XMFLOAT3PK & operator=(
    XMFLOAT3PK && unnamedParam1
  );
  void         XMFLOAT3PK(
    uint32_t Packed
  ) noexcept;
  void         XMFLOAT3PK(
    float _x,
    float _y,
    float _z
  ) noexcept;
  void         XMFLOAT3PK(
    const float *pArray
  ) noexcept;
  void         operator uint32_t() noexcept;
  XMFLOAT3PK & operator=(
    uint32_t Packed
  ) noexcept;
};