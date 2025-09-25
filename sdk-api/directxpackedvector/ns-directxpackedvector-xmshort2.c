struct XMSHORT2 {
  union {
    struct {
      int16_t x;
      int16_t y;
    };
    uint32_t v;
  };
  void       XMSHORT2();
  void       XMSHORT2(
    const XMSHORT2 & unnamedParam1
  );
  XMSHORT2 & operator=(
    const XMSHORT2 & unnamedParam1
  );
  void       XMSHORT2(
    XMSHORT2 && unnamedParam1
  );
  XMSHORT2 & operator=(
    XMSHORT2 && unnamedParam1
  );
  void       XMSHORT2(
    uint32_t Packed
  ) noexcept;
  void       XMSHORT2(
    int16_t _x,
    int16_t _y
  ) noexcept;
  void       XMSHORT2(
    const int16_t *pArray
  ) noexcept;
  void       XMSHORT2(
    float _x,
    float _y
  ) noexcept;
  void       XMSHORT2(
    const float *pArray
  ) noexcept;
  XMSHORT2 & operator=(
    uint32_t Packed
  ) noexcept;
};