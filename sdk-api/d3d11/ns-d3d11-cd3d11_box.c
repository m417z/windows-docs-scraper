struct CD3D11_BOX : D3D11_BOX {
  void CD3D11_BOX();
  void CD3D11_BOX(
    const D3D11_BOX & o
  );
  void CD3D11_BOX(
    LONG Left,
    LONG Top,
    LONG Front,
    LONG Right,
    LONG Bottom,
    LONG Back
  );
  void ~CD3D11_BOX();
};