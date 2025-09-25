struct XMFLOAT4 {
  float      x;
  float      y;
  float      z;
  float      w;
  void       XMFLOAT4();
  void       XMFLOAT4(
    const XMFLOAT4 & unnamedParam1
  );
  XMFLOAT4 & operator=(
    const XMFLOAT4 & unnamedParam1
  );
  void       XMFLOAT4(
    XMFLOAT4 && unnamedParam1
  );
  XMFLOAT4 & operator=(
    XMFLOAT4 && unnamedParam1
  );
  void       XMFLOAT4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void       XMFLOAT4(
    const float *pArray
  ) noexcept;
  bool       operator==(
    const XMFLOAT4 & unnamedParam1
  );
  auto       operator<=>(
    const XMFLOAT4 & unnamedParam1
  );
};