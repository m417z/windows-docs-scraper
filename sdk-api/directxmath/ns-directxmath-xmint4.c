struct XMINT4 {
  int32_t  x;
  int32_t  y;
  int32_t  z;
  int32_t  w;
  void     XMINT4();
  void     XMINT4(
    const XMINT4 & unnamedParam1
  );
  XMINT4 & operator=(
    const XMINT4 & unnamedParam1
  );
  void     XMINT4(
    XMINT4 && unnamedParam1
  );
  XMINT4 & operator=(
    XMINT4 && unnamedParam1
  );
  void     XMINT4(
    int32_t _x,
    int32_t _y,
    int32_t _z,
    int32_t _w
  ) noexcept;
  void     XMINT4(
    const int32_t *pArray
  ) noexcept;
  bool     operator==(
    const XMINT4 & unnamedParam1
  );
  auto     operator<=>(
    const XMINT4 & unnamedParam1
  );
};