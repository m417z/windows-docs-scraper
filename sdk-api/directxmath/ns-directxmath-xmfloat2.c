struct XMFLOAT2 {
  float      x;
  float      y;
  void       XMFLOAT2();
  void       XMFLOAT2(
    const XMFLOAT2 & unnamedParam1
  );
  XMFLOAT2 & operator=(
    const XMFLOAT2 & unnamedParam1
  );
  void       XMFLOAT2(
    XMFLOAT2 && unnamedParam1
  );
  XMFLOAT2 & operator=(
    XMFLOAT2 && unnamedParam1
  );
  void       XMFLOAT2(
    float _x,
    float _y
  ) noexcept;
  void       XMFLOAT2(
    const float *pArray
  ) noexcept;
  bool       operator==(
    const XMFLOAT2 & unnamedParam1
  );
  auto       operator<=>(
    const XMFLOAT2 & unnamedParam1
  );
};