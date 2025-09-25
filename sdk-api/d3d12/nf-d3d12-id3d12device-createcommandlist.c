HRESULT CreateCommandList(
  [in]           UINT                    nodeMask,
  [in]           D3D12_COMMAND_LIST_TYPE type,
  [in]           ID3D12CommandAllocator  *pCommandAllocator,
  [in, optional] ID3D12PipelineState     *pInitialState,
  [in]           REFIID                  riid,
  [out]          void                    **ppCommandList
);