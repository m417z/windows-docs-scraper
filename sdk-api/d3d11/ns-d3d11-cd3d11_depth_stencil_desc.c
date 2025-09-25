struct CD3D11_DEPTH_STENCIL_DESC : D3D11_DEPTH_STENCIL_DESC {
  void CD3D11_DEPTH_STENCIL_DESC();
  void CD3D11_DEPTH_STENCIL_DESC(
    const D3D11_DEPTH_STENCIL_DESC & o
  );
  void CD3D11_DEPTH_STENCIL_DESC(
    CD3D11_DEFAULT unnamedParam1
  );
  void CD3D11_DEPTH_STENCIL_DESC(
    BOOL                   depthEnable,
    D3D11_DEPTH_WRITE_MASK depthWriteMask,
    D3D11_COMPARISON_FUNC  depthFunc,
    BOOL                   stencilEnable,
    UINT8                  stencilReadMask,
    UINT8                  stencilWriteMask,
    D3D11_STENCIL_OP       frontStencilFailOp,
    D3D11_STENCIL_OP       frontStencilDepthFailOp,
    D3D11_STENCIL_OP       frontStencilPassOp,
    D3D11_COMPARISON_FUNC  frontStencilFunc,
    D3D11_STENCIL_OP       backStencilFailOp,
    D3D11_STENCIL_OP       backStencilDepthFailOp,
    D3D11_STENCIL_OP       backStencilPassOp,
    D3D11_COMPARISON_FUNC  backStencilFunc
  );
  void ~CD3D11_DEPTH_STENCIL_DESC();
};