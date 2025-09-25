struct XMDEC4 {
  union {
    struct {
      int32_t x : 10;
      int32_t y : 10;
      int32_t z : 10;
      int32_t w : 2;
    };
             uint32_t v;
  };
  void     XMDEC4();
  void     XMDEC4(
    const XMDEC4 & unnamedParam1
  );
  XMDEC4 & operator=(
    const XMDEC4 & unnamedParam1
  );
  void     XMDEC4(
    XMDEC4 && unnamedParam1
  );
  XMDEC4 & operator=(
    XMDEC4 && unnamedParam1
  );
  void     XMDEC4(
    uint32_t Packed
  ) noexcept;
  void     XMDEC4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void     XMDEC4(
    const float *pArray
  ) noexcept;
  void     operator uint32_t() noexcept;
  XMDEC4 & operator=(
    uint32_t Packed
  ) noexcept;
};