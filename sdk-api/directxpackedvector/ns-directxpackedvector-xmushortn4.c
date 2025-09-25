struct XMUSHORTN4 {
  union {
    struct {
      uint16_t x;
      uint16_t y;
      uint16_t z;
      uint16_t w;
    };
    uint64_t v;
  };
  void         XMUSHORTN4();
  void         XMUSHORTN4(
    const XMUSHORTN4 & unnamedParam1
  );
  XMUSHORTN4 & operator=(
    const XMUSHORTN4 & unnamedParam1
  );
  void         XMUSHORTN4(
    XMUSHORTN4 && unnamedParam1
  );
  XMUSHORTN4 & operator=(
    XMUSHORTN4 && unnamedParam1
  );
  void         XMUSHORTN4(
    uint64_t Packed
  ) noexcept;
  void         XMUSHORTN4(
    uint16_t _x,
    uint16_t _y,
    uint16_t _z,
    uint16_t _w
  ) noexcept;
  void         XMUSHORTN4(
    const uint16_t *pArray
  ) noexcept;
  void         XMUSHORTN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void         XMUSHORTN4(
    const float *pArray
  ) noexcept;
  XMUSHORTN4 & operator=(
    uint64_t Packed
  ) noexcept;
};