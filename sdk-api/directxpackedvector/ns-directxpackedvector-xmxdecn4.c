struct XMXDECN4 {
  union {
    struct {
      int32_t  x : 10;
      int32_t  y : 10;
      int32_t  z : 10;
      uint32_t w : 2;
    };
             uint32_t v;
  };
  void       XMXDECN4();
  void       XMXDECN4(
    const XMXDECN4 & unnamedParam1
  );
  XMXDECN4 & operator=(
    const XMXDECN4 & unnamedParam1
  );
  void       XMXDECN4(
    XMXDECN4 && unnamedParam1
  );
  XMXDECN4 & operator=(
    XMXDECN4 && unnamedParam1
  );
  void       XMXDECN4(
    uint32_t Packed
  );
  void       XMXDECN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void       XMXDECN4(
    const float *pArray
  ) noexcept;
  void       operator uint32_t() noexcept;
  XMXDECN4 & operator=(
    uint32_t Packed
  ) noexcept;
};