struct XMUINT4 {
  uint32_t  x;
  uint32_t  y;
  uint32_t  z;
  uint32_t  w;
  void      XMUINT4();
  void      XMUINT4(
    const XMUINT4 & unnamedParam1
  );
  XMUINT4 & operator=(
    const XMUINT4 & unnamedParam1
  );
  void      XMUINT4(
    XMUINT4 && unnamedParam1
  );
  XMUINT4 & operator=(
    XMUINT4 && unnamedParam1
  );
  void      XMUINT4(
    uint32_t _x,
    uint32_t _y,
    uint32_t _z,
    uint32_t _w
  ) noexcept;
  void      XMUINT4(
    const uint32_t *pArray
  ) noexcept;
  bool      operator==(
    const XMUINT4 & unnamedParam1
  );
  auto      operator<=>(
    const XMUINT4 & unnamedParam1
  );
};