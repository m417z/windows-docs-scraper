typedef struct D3D12DDI_WORK_GRAPH_DESC_0108 {
  LPCWSTR                             ProgramName;
  UINT                                Version;
  D3D12DDI_WORK_GRAPH_FLAGS_0108      Flags;
  UINT                                NumNodes;
  const D3D12DDI_NODE_LIST_ENTRY_0108 *pNodes;
  UINT                                NumEntrypoints;
  const D3D12DDI_NODE_LIST_ENTRY_0108 *pEntrypoints;
} D3D12DDI_WORK_GRAPH_DESC_0108;