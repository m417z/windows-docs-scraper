typedef struct D3D11_VIDEO_DECODER_EXTENSION {
  UINT           Function;
  void           *pPrivateInputData;
  UINT           PrivateInputDataSize;
  void           *pPrivateOutputData;
  UINT           PrivateOutputDataSize;
  UINT           ResourceCount;
  ID3D11Resource **ppResourceList;
} D3D11_VIDEO_DECODER_EXTENSION;