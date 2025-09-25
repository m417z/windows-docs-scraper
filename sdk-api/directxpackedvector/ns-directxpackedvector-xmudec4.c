struct XMUDEC4 {
  union {
    struct {
      uint32_t x : 10;
      uint32_t y : 10;
      uint32_t z : 10;
      uint32_t w : 2;
    };
             uint32_t v;
  };
  void      XMUDEC4();
  void      XMUDEC4(
    const XMUDEC4 & unnamedParam1
  );
  XMUDEC4 & operator=(
    const XMUDEC4 & unnamedParam1
  );
  void      XMUDEC4(
    XMUDEC4 && unnamedParam1
  );
  XMUDEC4 & operator=(
    XMUDEC4 && unnamedParam1
  );
  void      XMUDEC4(
    uint32_t Packed
  ) noexcept;
  void      XMUDEC4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void      XMUDEC4(
    const float *pArray
  ) noexcept;
  void      operator uint32_t() noexcept;
  XMUDEC4 & operator=(
    uint32_t Packed
  ) noexcept;
};