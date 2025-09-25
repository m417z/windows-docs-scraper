struct XMCOLOR {
  union {
    struct {
      uint8_t b;
      uint8_t g;
      uint8_t r;
      uint8_t a;
    };
             uint32_t c;
  };
  void      XMCOLOR();
  void      XMCOLOR(
    const XMCOLOR & unnamedParam1
  );
  XMCOLOR & operator=(
    const XMCOLOR & unnamedParam1
  );
  void      XMCOLOR(
    XMCOLOR && unnamedParam1
  );
  XMCOLOR & operator=(
    XMCOLOR && unnamedParam1
  );
  void      XMCOLOR(
    uint32_t Color
  ) noexcept;
  void      XMCOLOR(
    float _r,
    float _g,
    float _b,
    float _a
  ) noexcept;
  void      XMCOLOR(
    const float *pArray
  ) noexcept;
  void      operator uint32_t() noexcept;
  XMCOLOR & operator=(
    const uint32_t Color
  ) noexcept;
};