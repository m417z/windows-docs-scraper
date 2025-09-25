struct XMHALF2 {
  union {
    struct {
      HALF x;
      HALF y;
    };
    uint32_t v;
  };
  void      XMHALF2();
  void      XMHALF2(
    const XMHALF2 & unnamedParam1
  );
  XMHALF2 & operator=(
    const XMHALF2 & unnamedParam1
  );
  void      XMHALF2(
    XMHALF2 && unnamedParam1
  );
  XMHALF2 & operator=(
    XMHALF2 && unnamedParam1
  );
  void      XMHALF2(
    uint32_t Packed
  ) noexcept;
  void      XMHALF2(
    HALF _x,
    HALF _y
  ) noexcept;
  void      XMHALF2(
    const HALF *pArray
  ) noexcept;
  void      XMHALF2(
    float _x,
    float _y
  ) noexcept;
  void      XMHALF2(
    const float *pArray
  ) noexcept;
  XMHALF2 & operator=(
    uint32_t Packed
  ) noexcept;
};