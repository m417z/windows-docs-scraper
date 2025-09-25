struct XMDECN4 {
  union {
    struct {
      int32_t x : 10;
      int32_t y : 10;
      int32_t z : 10;
      int32_t w : 2;
    };
             uint32_t v;
  };
  void      XMDECN4();
  void      XMDECN4(
    const XMDECN4 & unnamedParam1
  );
  XMDECN4 & operator=(
    const XMDECN4 & unnamedParam1
  );
  void      XMDECN4(
    XMDECN4 && unnamedParam1
  );
  XMDECN4 & operator=(
    XMDECN4 && unnamedParam1
  );
  void      XMDECN4(
    uint32_t Packed
  ) noexcept;
  void      XMDECN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void      XMDECN4(
    const float *pArray
  ) noexcept;
  void      operator uint32_t() noexcept;
  XMDECN4 & operator=(
    uint32_t Packed
  ) noexcept;
};