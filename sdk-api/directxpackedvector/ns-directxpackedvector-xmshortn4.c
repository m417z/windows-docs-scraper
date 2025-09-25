struct XMSHORTN4 {
  union {
    struct {
      int16_t x;
      int16_t y;
      int16_t z;
      int16_t w;
    };
    uint64_t v;
  };
  void        XMSHORTN4();
  void        XMSHORTN4(
    const XMSHORTN4 & unnamedParam1
  );
  XMSHORTN4 & operator=(
    const XMSHORTN4 & unnamedParam1
  );
  void        XMSHORTN4(
    XMSHORTN4 && unnamedParam1
  );
  XMSHORTN4 & operator=(
    XMSHORTN4 && unnamedParam1
  );
  void        XMSHORTN4(
    uint64_t Packed
  ) noexcept;
  void        XMSHORTN4(
    int16_t _x,
    int16_t _y,
    int16_t _z,
    int16_t _w
  ) noexcept;
  void        XMSHORTN4(
    const int16_t *pArray
  ) noexcept;
  void        XMSHORTN4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void        XMSHORTN4(
    const float *pArray
  ) noexcept;
  XMSHORTN4 & operator=(
    uint64_t Packed
  ) noexcept;
};