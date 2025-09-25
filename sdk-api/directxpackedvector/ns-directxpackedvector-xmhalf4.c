struct XMHALF4 {
  union {
    struct {
      HALF x;
      HALF y;
      HALF z;
      HALF w;
    };
    uint64_t v;
  };
  void      XMHALF4();
  void      XMHALF4(
    const XMHALF4 & unnamedParam1
  );
  XMHALF4 & operator=(
    const XMHALF4 & unnamedParam1
  );
  void      XMHALF4(
    XMHALF4 && unnamedParam1
  );
  XMHALF4 & operator=(
    XMHALF4 && unnamedParam1
  );
  void      XMHALF4(
    uint64_t Packed
  ) noexcept;
  void      XMHALF4(
    HALF _x,
    HALF _y,
    HALF _z,
    HALF _w
  ) noexcept;
  void      XMHALF4(
    const HALF *pArray
  ) noexcept;
  void      XMHALF4(
    float _x,
    float _y,
    float _z,
    float _w
  ) noexcept;
  void      XMHALF4(
    const float *pArray
  ) noexcept;
  XMHALF4 & operator=(
    uint64_t Packed
  ) noexcept;
};