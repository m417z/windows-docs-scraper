struct XMUSHORT2 {
  union {
    struct {
      uint16_t x;
      uint16_t y;
    };
    uint32_t v;
  };
  void        XMUSHORT2();
  void        XMUSHORT2(
    const XMUSHORT2 & unnamedParam1
  );
  XMUSHORT2 & operator=(
    const XMUSHORT2 & unnamedParam1
  );
  void        XMUSHORT2(
    XMUSHORT2 && unnamedParam1
  );
  XMUSHORT2 & operator=(
    XMUSHORT2 && unnamedParam1
  );
  void        XMUSHORT2(
    uint32_t Packed
  ) noexcept;
  void        XMUSHORT2(
    uint16_t _x,
    uint16_t _y
  ) noexcept;
  void        XMUSHORT2(
    const uint16_t *pArray
  ) noexcept;
  void        XMUSHORT2(
    float _x,
    float _y
  ) noexcept;
  void        XMUSHORT2(
    const float *pArray
  ) noexcept;
  XMUSHORT2 & operator=(
    uint32_t Packed
  ) noexcept;
};