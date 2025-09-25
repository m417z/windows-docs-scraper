struct XMUINT3 {
  uint32_t  x;
  uint32_t  y;
  uint32_t  z;
  void      XMUINT3();
  void      XMUINT3(
    const XMUINT3 & unnamedParam1
  );
  XMUINT3 & operator=(
    const XMUINT3 & unnamedParam1
  );
  void      XMUINT3(
    XMUINT3 && unnamedParam1
  );
  XMUINT3 & operator=(
    XMUINT3 && unnamedParam1
  );
  void      XMUINT3(
    uint32_t _x,
    uint32_t _y,
    uint32_t _z
  ) noexcept;
  void      XMUINT3(
    const uint32_t *pArray
  ) noexcept;
  bool      operator==(
    const XMUINT3 & unnamedParam1
  );
  auto      operator<=>(
    const XMUINT3 & unnamedParam1
  );
};