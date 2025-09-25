struct XMU555 {
  union {
    struct {
      uint16_t x : 5;
      uint16_t y : 5;
      uint16_t z : 5;
      uint16_t w : 1;
    };
      uint16_t v;
  };
  void     XMU555();
  void     XMU555(
    const XMU555 & unnamedParam1
  );
  XMU555 & operator=(
    const XMU555 & unnamedParam1
  );
  void     XMU555(
    XMU555 && unnamedParam1
  );
  XMU555 & operator=(
    XMU555 && unnamedParam1
  );
  void     XMU555(
    uint16_t Packed
  ) noexcept;
  void     XMU555(
    uint8_t _x,
    uint8_t _y,
    uint8_t _z,
    bool    _w
  ) noexcept;
  void     XMU555(
    const uint8_t *pArray,
    bool          _w
  ) noexcept;
  void     XMU555(
    float _x,
    float _y,
    float _z,
    bool  _w
  ) noexcept;
  void     XMU555(
    const float *pArray,
    bool        _w
  ) noexcept;
  void     operator uint16_t() noexcept;
  XMU555 & operator=(
    uint16_t Packed
  ) noexcept;
};