struct XMBYTE2 {
  union {
    struct {
      int8_t x;
      int8_t y;
    };
    uint16_t v;
  };
  void      XMBYTE2();
  void      XMBYTE2(
    const XMBYTE2 & unnamedParam1
  );
  XMBYTE2 & operator=(
    const XMBYTE2 & unnamedParam1
  );
  void      XMBYTE2(
    XMBYTE2 && unnamedParam1
  );
  XMBYTE2 & operator=(
    XMBYTE2 && unnamedParam1
  );
  void      XMBYTE2(
    uint16_t Packed
  ) noexcept;
  void      XMBYTE2(
    int8_t _x,
    int8_t _y
  ) noexcept;
  void      XMBYTE2(
    const int8_t *pArray
  ) noexcept;
  void      XMBYTE2(
    float _x,
    float _y
  ) noexcept;
  void      XMBYTE2(
    const float *pArray
  ) noexcept;
  XMBYTE2 & operator=(
    uint16_t Packed
  ) noexcept;
};