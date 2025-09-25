struct XMUBYTEN4 {
  union {
    struct {
      uint8_t x;
      uint8_t y;
      uint8_t z;
      uint8_t w;
    };
    uint32_t v;
  };
  void        XMUBYTEN4();
  void        XMUBYTEN4(
    const XMUBYTEN4 & unnamedParam1
  );
  XMUBYTEN4 & operator=(
    const XMUBYTEN4 & unnamedParam1
  );
  void        XMUBYTEN4(
    XMUBYTEN4 && unnamedParam1
  );
  XMUBYTEN4 & operator=(
    XMUBYTEN4 && unnamedParam1
  );
  void        XMUBYTEN4(
    uint8_t _x,
    uint8_t _y,
    uint8_t _z,
    uint8_t _w
  ) noexcept;
  void        XMUBYTEN4(
    uint32_t Packed
  ) noexcept;
  void        XMUBYTEN4(
    const uint8_t *pArray
  ) noexcept;
  void        XMUBYTEN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void        XMUBYTEN4(
    const float *pArray
  ) noexcept;
  XMUBYTEN4 & operator=(
    uint32_t Packed
  ) noexcept;
};