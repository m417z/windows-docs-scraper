void ClearDepthStencilView(
  [in] D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
  [in] D3D12_CLEAR_FLAGS           ClearFlags,
  [in] FLOAT                       Depth,
  [in] UINT8                       Stencil,
  [in] UINT                        NumRects,
  [in] const D3D12_RECT            *pRects
);