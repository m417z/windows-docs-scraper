struct XMUDECN4 {
  union {
    struct {
      uint32_t x : 10;
      uint32_t y : 10;
      uint32_t z : 10;
      uint32_t w : 2;
    };
             uint32_t v;
  };
  void       XMUDECN4();
  void       XMUDECN4(
    const XMUDECN4 & unnamedParam1
  );
  XMUDECN4 & operator=(
    const XMUDECN4 & unnamedParam1
  );
  void       XMUDECN4(
    XMUDECN4 && unnamedParam1
  );
  XMUDECN4 & operator=(
    XMUDECN4 && unnamedParam1
  );
  void       XMUDECN4(
    uint32_t Packed
  ) noexcept;
  void       XMUDECN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void       XMUDECN4(
    const float *pArray
  ) noexcept;
  void       operator uint32_t() noexcept;
  XMUDECN4 & operator=(
    uint32_t Packed
  ) noexcept;
};