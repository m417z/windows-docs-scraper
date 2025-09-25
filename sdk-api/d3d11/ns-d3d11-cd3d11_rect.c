struct CD3D11_RECT : D3D11_RECT {
  void CD3D11_RECT();
  void CD3D11_RECT(
    const D3D11_RECT & o
  );
  void CD3D11_RECT(
    LONG Left,
    LONG Top,
    LONG Right,
    LONG Bottom
  );
  void ~CD3D11_RECT();
};