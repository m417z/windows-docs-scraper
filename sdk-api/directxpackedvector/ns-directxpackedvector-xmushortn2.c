struct XMUSHORTN2 {
  union {
    struct {
      uint16_t x;
      uint16_t y;
    };
    uint32_t v;
  };
  void         XMUSHORTN2();
  void         XMUSHORTN2(
    const XMUSHORTN2 & unnamedParam1
  );
  XMUSHORTN2 & operator=(
    const XMUSHORTN2 & unnamedParam1
  );
  void         XMUSHORTN2(
    XMUSHORTN2 && unnamedParam1
  );
  XMUSHORTN2 & operator=(
    XMUSHORTN2 && unnamedParam1
  );
  void         XMUSHORTN2(
    uint32_t Packed
  ) noexcept;
  void         XMUSHORTN2(
    uint16_t _x,
    uint16_t _y
  ) noexcept;
  void         XMUSHORTN2(
    const uint16_t *pArray
  ) noexcept;
  void         XMUSHORTN2(
    float _x,
    float _y
  ) noexcept;
  void         XMUSHORTN2(
    const float *pArray
  ) noexcept;
  XMUSHORTN2 & operator=(
    uint32_t Packed
  ) noexcept;
};