struct XMUBYTEN2 {
  union {
    struct {
      uint8_t x;
      uint8_t y;
    };
    uint16_t v;
  };
  void        XMUBYTEN2();
  void        XMUBYTEN2(
    const XMUBYTEN2 & unnamedParam1
  );
  XMUBYTEN2 & operator=(
    const XMUBYTEN2 & unnamedParam1
  );
  void        XMUBYTEN2(
    XMUBYTEN2 && unnamedParam1
  );
  XMUBYTEN2 & operator=(
    XMUBYTEN2 && unnamedParam1
  );
  void        XMUBYTEN2(
    uint16_t Packed
  ) noexcept;
  void        XMUBYTEN2(
    uint8_t _x,
    uint8_t _y
  ) noexcept;
  void        XMUBYTEN2(
    const uint8_t *pArray
  ) noexcept;
  void        XMUBYTEN2(
    float _x,
    float _y
  ) noexcept;
  void        XMUBYTEN2(
    const float *pArray
  ) noexcept;
  XMUBYTEN2 & operator=(
    uint16_t Packed
  ) noexcept;
};