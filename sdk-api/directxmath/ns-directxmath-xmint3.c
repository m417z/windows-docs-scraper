struct XMINT3 {
  int32_t  x;
  int32_t  y;
  int32_t  z;
  void     XMINT3();
  void     XMINT3(
    const XMINT3 & unnamedParam1
  );
  XMINT3 & operator=(
    const XMINT3 & unnamedParam1
  );
  void     XMINT3(
    XMINT3 && unnamedParam1
  );
  XMINT3 & operator=(
    XMINT3 && unnamedParam1
  );
  void     XMINT3(
    int32_t _x,
    int32_t _y,
    int32_t _z
  ) noexcept;
  void     XMINT3(
    const int32_t *pArray
  ) noexcept;
  bool     operator==(
    const XMINT3 & unnamedParam1
  );
  auto     operator<=>(
    const XMINT3 & unnamedParam1
  );
};