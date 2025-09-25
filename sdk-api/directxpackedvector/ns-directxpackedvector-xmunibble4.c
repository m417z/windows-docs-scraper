struct XMUNIBBLE4 {
  union {
    struct {
      uint16_t x : 4;
      uint16_t y : 4;
      uint16_t z : 4;
      uint16_t w : 4;
    };
      uint16_t v;
  };
  void         XMUNIBBLE4();
  void         XMUNIBBLE4(
    const XMUNIBBLE4 & unnamedParam1
  );
  XMUNIBBLE4 & operator=(
    const XMUNIBBLE4 & unnamedParam1
  );
  void         XMUNIBBLE4(
    XMUNIBBLE4 && unnamedParam1
  );
  XMUNIBBLE4 & operator=(
    XMUNIBBLE4 && unnamedParam1
  );
  void         XMUNIBBLE4(
    uint16_t Packed
  ) noexcept;
  void         XMUNIBBLE4(
    uint8_t _x,
    uint8_t _y,
    uint8_t _z,
    uint8_t _w
  ) noexcept;
  void         XMUNIBBLE4(
    const uint8_t *pArray
  ) noexcept;
  void         XMUNIBBLE4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void         XMUNIBBLE4(
    const float *pArray
  ) noexcept;
  void         operator uint16_t() noexcept;
  XMUNIBBLE4 & operator=(
    uint16_t Packed
  ) noexcept;
};