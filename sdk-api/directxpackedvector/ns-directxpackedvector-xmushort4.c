struct XMUSHORT4 {
  union {
    struct {
      uint16_t x;
      uint16_t y;
      uint16_t z;
      uint16_t w;
    };
    uint64_t v;
  };
  void        XMUSHORT4();
  void        XMUSHORT4(
    const XMUSHORT4 & unnamedParam1
  );
  XMUSHORT4 & operator=(
    const XMUSHORT4 & unnamedParam1
  );
  void        XMUSHORT4(
    XMUSHORT4 && unnamedParam1
  );
  XMUSHORT4 & operator=(
    XMUSHORT4 && unnamedParam1
  );
  void        XMUSHORT4(
    uint64_t Packed
  ) noexcept;
  void        XMUSHORT4(
    uint16_t _x,
    uint16_t _y,
    uint16_t _z,
    uint16_t _w
  ) noexcept;
  void        XMUSHORT4(
    const uint16_t *pArray
  ) noexcept;
  void        XMUSHORT4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void        XMUSHORT4(
    const float *pArray
  ) noexcept;
  XMUSHORT4 & operator=(
    uint32_t Packed
  ) noexcept;
};