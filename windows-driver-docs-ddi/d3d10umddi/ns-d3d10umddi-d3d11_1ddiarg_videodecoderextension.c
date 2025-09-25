typedef struct D3D11_1DDIARG_VIDEODECODEREXTENSION {
  UINT               Function;
  void               *pPrivateInputData;
  UINT               PrivateInputDataSize;
  void               *pPrivateOutputData;
  UINT               PrivateOutputDataSize;
  UINT               ResourceCount;
  D3D10DDI_HRESOURCE *pResourceList;
} D3D11_1DDIARG_VIDEODECODEREXTENSION;