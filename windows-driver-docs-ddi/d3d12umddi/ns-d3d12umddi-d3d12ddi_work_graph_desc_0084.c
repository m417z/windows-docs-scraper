typedef struct D3D12DDI_WORK_GRAPH_DESC_0084 {
  LPCWSTR                  ProgramName;
  UINT                     NumNodes;
  const D3D12DDI_NODE_0084 const * * ppNodes;
  UINT                     NumEntrypoints;
  const UINT               *pEntrypointNodeIndices;
} D3D12DDI_WORK_GRAPH_DESC_0084;