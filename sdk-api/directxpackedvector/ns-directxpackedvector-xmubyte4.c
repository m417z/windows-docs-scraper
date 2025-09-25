struct XMUBYTE4 {
  union {
    struct {
      uint8_t x;
      uint8_t y;
      uint8_t z;
      uint8_t w;
    };
    uint32_t v;
  };
  void       XMUBYTE4();
  void       XMUBYTE4(
    const XMUBYTE4 & unnamedParam1
  );
  XMUBYTE4 & operator=(
    const XMUBYTE4 & unnamedParam1
  );
  void       XMUBYTE4(
    XMUBYTE4 && unnamedParam1
  );
  XMUBYTE4 & operator=(
    XMUBYTE4 && unnamedParam1
  );
  void       XMUBYTE4(
    uint8_t _x,
    uint8_t _y,
    uint8_t _z,
    uint8_t _w
  ) noexcept;
  void       XMUBYTE4(
    uint32_t Packed
  ) noexcept;
  void       XMUBYTE4(
    const uint8_t *pArray
  ) noexcept;
  void       XMUBYTE4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void       XMUBYTE4(
    const float *pArray
  ) noexcept;
  XMUBYTE4 & operator=(
    uint32_t Packed
  ) noexcept;
};