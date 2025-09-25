HRESULT CreateResourceTexture(
  [in, optional] const GUID                             *resourceId,
  [in]           const D2D1_RESOURCE_TEXTURE_PROPERTIES *resourceTextureProperties,
  [in, optional] const BYTE                             *data,
  [in, optional] const UINT32                           *strides,
                 UINT32                                 dataSize,
  [out]          ID2D1ResourceTexture                   **resourceTexture
);