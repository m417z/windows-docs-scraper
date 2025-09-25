struct XMXDEC4 {
  union {
    struct {
      int32_t  x : 10;
      int32_t  y : 10;
      int32_t  z : 10;
      uint32_t w : 2;
    };
             uint32_t v;
  };
  void      XMXDEC4();
  void      XMXDEC4(
    const XMXDEC4 & unnamedParam1
  );
  XMXDEC4 & operator=(
    const XMXDEC4 & unnamedParam1
  );
  void      XMXDEC4(
    XMXDEC4 && unnamedParam1
  );
  XMXDEC4 & operator=(
    XMXDEC4 && unnamedParam1
  );
  void      XMXDEC4(
    uint32_t Packed
  ) noexcept;
  void      XMXDEC4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void      XMXDEC4(
    const float *pArray
  ) noexcept;
  void      operator uint32_t() noexcept;
  XMXDEC4 & operator=(
    uint32_t Packed
  ) noexcept;
};