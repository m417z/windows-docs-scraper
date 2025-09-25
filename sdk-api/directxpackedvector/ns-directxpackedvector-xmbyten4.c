struct XMBYTEN4 {
  union {
    struct {
      int8_t x;
      int8_t y;
      int8_t z;
      int8_t w;
    };
    uint32_t v;
  };
  void       XMBYTEN4();
  void       XMBYTEN4(
    const XMBYTEN4 & unnamedParam1
  );
  XMBYTEN4 & operator=(
    const XMBYTEN4 & unnamedParam1
  );
  void       XMBYTEN4(
    XMBYTEN4 && unnamedParam1
  );
  XMBYTEN4 & operator=(
    XMBYTEN4 && unnamedParam1
  );
  void       XMBYTEN4(
    int8_t _x,
    int8_t _y,
    int8_t _z,
    int8_t _w
  ) noexcept;
  void       XMBYTEN4(
    uint32_t Packed
  ) noexcept;
  void       XMBYTEN4(
    const int8_t *pArray
  ) noexcept;
  void       XMBYTEN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void       XMBYTEN4(
    const float *pArray
  ) noexcept;
  XMBYTEN4 & operator=(
    uint32_t Packed
  ) noexcept;
};