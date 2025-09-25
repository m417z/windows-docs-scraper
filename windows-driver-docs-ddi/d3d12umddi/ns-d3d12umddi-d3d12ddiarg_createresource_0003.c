typedef struct D3D12DDIARG_CREATERESOURCE_0003 {
  D3D12DDIARG_BUFFER_PLACEMENT                ReuseBufferGPUVA;
  D3D12DDI_RESOURCE_TYPE                      ResourceType;
  UINT64                                      Width;
  UINT                                        Height;
  UINT16                                      DepthOrArraySize;
  UINT16                                      MipLevels;
  DXGI_FORMAT                                 Format;
  DXGI_SAMPLE_DESC                            SampleDesc;
  D3D12DDI_TEXTURE_LAYOUT                     Layout;
  D3D12DDI_RESOURCE_FLAGS_0003                Flags;
  D3D12DDI_RESOURCE_STATES                    InitialResourceState;
  const D3D12DDIARG_ROW_MAJOR_RESOURCE_LAYOUT *pRowMajorLayout;
} D3D12DDIARG_CREATERESOURCE_0003;