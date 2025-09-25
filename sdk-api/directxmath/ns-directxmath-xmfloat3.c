struct XMFLOAT3 {
  float      x;
  float      y;
  float      z;
  void       XMFLOAT3();
  void       XMFLOAT3(
    const XMFLOAT3 & unnamedParam1
  );
  XMFLOAT3 & operator=(
    const XMFLOAT3 & unnamedParam1
  );
  void       XMFLOAT3(
    XMFLOAT3 && unnamedParam1
  );
  XMFLOAT3 & operator=(
    XMFLOAT3 && unnamedParam1
  );
  void       XMFLOAT3(
    float _x,
    float _y,
    float _z
  ) noexcept;
  void       XMFLOAT3(
    const float *pArray
  ) noexcept;
};