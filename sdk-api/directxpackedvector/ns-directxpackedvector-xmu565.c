struct XMU565 {
  union {
    struct {
      uint16_t x : 5;
      uint16_t y : 6;
      uint16_t z : 5;
    };
      uint16_t v;
  };
  void     XMU565();
  void     XMU565(
    const XMU565 & unnamedParam1
  );
  XMU565 & operator=(
    const XMU565 & unnamedParam1
  );
  void     XMU565(
    XMU565 && unnamedParam1
  );
  XMU565 & operator=(
    XMU565 && unnamedParam1
  );
  void     XMU565(
    uint16_t Packed
  ) noexcept;
  void     XMU565(
    uint8_t _x,
    uint8_t _y,
    uint8_t _z
  ) noexcept;
  void     XMU565(
    const uint8_t *pArray
  ) noexcept;
  void     XMU565(
    float _x,
    float _y,
    float _z
  ) noexcept;
  void     XMU565(
    const float *pArray
  ) noexcept;
  void     operator uint16_t() noexcept;
  XMU565 & operator=(
    uint16_t Packed
  ) noexcept;
};