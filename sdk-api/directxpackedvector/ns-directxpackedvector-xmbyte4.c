struct XMBYTE4 {
  union {
    struct {
      int8_t x;
      int8_t y;
      int8_t z;
      int8_t w;
    };
    uint32_t v;
  };
  void      XMBYTE4();
  void      XMBYTE4(
    const XMBYTE4 & unnamedParam1
  );
  XMBYTE4 & operator=(
    const XMBYTE4 & unnamedParam1
  );
  void      XMBYTE4(
    XMBYTE4 && unnamedParam1
  );
  XMBYTE4 & operator=(
    XMBYTE4 && unnamedParam1
  );
  void      XMBYTE4(
    int8_t _x,
    int8_t _y,
    int8_t _z,
    int8_t _w
  ) noexcept;
  void      XMBYTE4(
    uint32_t Packed
  ) noexcept;
  void      XMBYTE4(
    const int8_t *pArray
  ) noexcept;
  void      XMBYTE4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void      XMBYTE4(
    const float *pArray
  ) noexcept;
  XMBYTE4 & operator=(
    uint32_t Packed
  ) noexcept;
};