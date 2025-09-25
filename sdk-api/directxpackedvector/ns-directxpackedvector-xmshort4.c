struct XMSHORT4 {
  union {
    struct {
      int16_t x;
      int16_t y;
      int16_t z;
      int16_t w;
    };
    uint64_t v;
  };
  void       XMSHORT4();
  void       XMSHORT4(
    const XMSHORT4 & unnamedParam1
  );
  XMSHORT4 & operator=(
    const XMSHORT4 & unnamedParam1
  );
  void       XMSHORT4(
    XMSHORT4 && unnamedParam1
  );
  XMSHORT4 & operator=(
    XMSHORT4 && unnamedParam1
  );
  void       XMSHORT4(
    uint64_t Packed
  ) noexcept;
  void       XMSHORT4(
    int16_t _x,
    int16_t _y,
    int16_t _z,
    int16_t _w
  ) noexcept;
  void       XMSHORT4(
    const int16_t *pArray
  ) noexcept;
  void       XMSHORT4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void       XMSHORT4(
    const float *pArray
  ) noexcept;
  XMSHORT4 & operator=(
    uint64_t Packed
  ) noexcept;
};