struct XMUINT2 {
  uint32_t  x;
  uint32_t  y;
  void      XMUINT2();
  void      XMUINT2(
    const XMUINT2 & unnamedParam1
  );
  XMUINT2 & operator=(
    const XMUINT2 & unnamedParam1
  );
  void      XMUINT2(
    XMUINT2 && unnamedParam1
  );
  XMUINT2 & operator=(
    XMUINT2 && unnamedParam1
  );
  void      XMUINT2(
    uint32_t _x,
    uint32_t _y
  ) noexcept;
  void      XMUINT2(
    const uint32_t *pArray
  ) noexcept;
  bool      operator==(
    const XMUINT2 & unnamedParam1
  );
  auto      operator<=>(
    const XMUINT2 & unnamedParam1
  );
};