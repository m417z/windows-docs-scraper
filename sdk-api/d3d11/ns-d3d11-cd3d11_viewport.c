struct CD3D11_VIEWPORT : D3D11_VIEWPORT {
  void CD3D11_VIEWPORT();
  void CD3D11_VIEWPORT(
    const D3D11_VIEWPORT & o
  );
  void CD3D11_VIEWPORT(
    FLOAT topLeftX,
    FLOAT topLeftY,
    FLOAT width,
    FLOAT height,
    FLOAT minDepth,
    FLOAT maxDepth
  );
  void CD3D11_VIEWPORT(
    ID3D11Buffer           *unnamedParam1,
    ID3D11RenderTargetView *pRTView,
    FLOAT                  topLeftX,
    FLOAT                  minDepth,
    FLOAT                  maxDepth
  );
  void CD3D11_VIEWPORT(
    ID3D11Texture1D        *pTex1D,
    ID3D11RenderTargetView *pRTView,
    FLOAT                  topLeftX,
    FLOAT                  minDepth,
    FLOAT                  maxDepth
  );
  void CD3D11_VIEWPORT(
    ID3D11Texture2D        *pTex2D,
    ID3D11RenderTargetView *pRTView,
    FLOAT                  topLeftX,
    FLOAT                  topLeftY,
    FLOAT                  minDepth,
    FLOAT                  maxDepth
  );
  void CD3D11_VIEWPORT(
    ID3D11Texture3D        *pTex3D,
    ID3D11RenderTargetView *pRTView,
    FLOAT                  topLeftX,
    FLOAT                  topLeftY,
    FLOAT                  minDepth,
    FLOAT                  maxDepth
  );
  void ~CD3D11_VIEWPORT();
};