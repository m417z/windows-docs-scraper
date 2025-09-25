struct XMSHORTN2 {
  union {
    struct {
      int16_t x;
      int16_t y;
    };
    uint32_t v;
  };
  void        XMSHORTN2();
  void        XMSHORTN2(
    const XMSHORTN2 & unnamedParam1
  );
  XMSHORTN2 & operator=(
    const XMSHORTN2 & unnamedParam1
  );
  void        XMSHORTN2(
    XMSHORTN2 && unnamedParam1
  );
  XMSHORTN2 & operator=(
    XMSHORTN2 && unnamedParam1
  );
  void        XMSHORTN2(
    uint32_t Packed
  ) noexcept;
  void        XMSHORTN2(
    int16_t _x,
    int16_t _y
  ) noexcept;
  void        XMSHORTN2(
    const int16_t *pArray
  ) noexcept;
  void        XMSHORTN2(
    float _x,
    float _y
  ) noexcept;
  void        XMSHORTN2(
    const float *pArray
  ) noexcept;
  XMSHORTN2 & operator=(
    uint32_t Packed
  ) noexcept;
};