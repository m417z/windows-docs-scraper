struct XMINT2 {
  int32_t  x;
  int32_t  y;
  void     XMINT2();
  void     XMINT2(
    const XMINT2 & unnamedParam1
  );
  XMINT2 & operator=(
    const XMINT2 & unnamedParam1
  );
  void     XMINT2(
    XMINT2 && unnamedParam1
  );
  XMINT2 & operator=(
    XMINT2 && unnamedParam1
  );
  void     XMINT2(
    int32_t _x,
    int32_t _y
  ) noexcept;
  void     XMINT2(
    const int32_t *pArray
  ) noexcept;
  bool     operator==(
    const XMINT2 & unnamedParam1
  );
  auto     operator<=>(
    const XMINT2 & unnamedParam1
  );
};