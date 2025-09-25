typedef struct D3D12DDI_DEPTH_STENCIL_DESC_0025 {
  BOOL                            DepthEnable;
  D3D12DDI_DEPTH_WRITE_MASK       DepthWriteMask;
  D3D12DDI_COMPARISON_FUNC        DepthFunc;
  BOOL                            StencilEnable;
  BOOL                            FrontEnable;
  BOOL                            BackEnable;
  UINT8                           StencilReadMask;
  UINT8                           StencilWriteMask;
  D3D12DDI_DEPTH_STENCILOP_DESC   FrontFace;
  D3D12DDI_DEPTH_STENCILOP_DESC   BackFace;
  D3D12DDI_LIBRARY_REFERENCE_0010 LibraryReference;
  BOOL                            DepthBoundsTestEnable;
} D3D12DDI_DEPTH_STENCIL_DESC_0025;