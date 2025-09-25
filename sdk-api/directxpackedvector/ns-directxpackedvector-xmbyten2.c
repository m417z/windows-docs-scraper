struct XMBYTEN2 {
  union {
    struct {
      int8_t x;
      int8_t y;
    };
    uint16_t v;
  };
  void       XMBYTEN2();
  void       XMBYTEN2(
    const XMBYTEN2 & unnamedParam1
  );
  XMBYTEN2 & operator=(
    const XMBYTEN2 & unnamedParam1
  );
  void       XMBYTEN2(
    XMBYTEN2 && unnamedParam1
  );
  XMBYTEN2 & operator=(
    XMBYTEN2 && unnamedParam1
  );
  void       XMBYTEN2(
    uint16_t Packed
  ) noexcept;
  void       XMBYTEN2(
    int8_t _x,
    int8_t _y
  ) noexcept;
  void       XMBYTEN2(
    const int8_t *pArray
  ) noexcept;
  void       XMBYTEN2(
    float _x,
    float _y
  ) noexcept;
  void       XMBYTEN2(
    const float *pArray
  ) noexcept;
  XMBYTEN2 & operator=(
    uint16_t Packed
  ) noexcept;
};