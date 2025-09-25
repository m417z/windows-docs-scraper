struct XMUBYTE2 {
  union {
    struct {
      uint8_t x;
      uint8_t y;
    };
    uint16_t v;
  };
  void       XMUBYTE2();
  void       XMUBYTE2(
    const XMUBYTE2 & unnamedParam1
  );
  XMUBYTE2 & operator=(
    const XMUBYTE2 & unnamedParam1
  );
  void       XMUBYTE2(
    XMUBYTE2 && unnamedParam1
  );
  XMUBYTE2 & operator=(
    XMUBYTE2 && unnamedParam1
  );
  void       XMUBYTE2(
    uint16_t Packed
  ) noexcept;
  void       XMUBYTE2(
    uint8_t _x,
    uint8_t _y
  ) noexcept;
  void       XMUBYTE2(
    const uint8_t *pArray
  ) noexcept;
  void       XMUBYTE2(
    float _x,
    float _y
  ) noexcept;
  void       XMUBYTE2(
    const float *pArray
  ) noexcept;
  XMUBYTE2 & operator=(
    uint16_t Packed
  ) noexcept;
};