typedef struct D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0084 {
  D3D12DDI_NODE_ID_0084           FinalName;
  BOOL                            bProgramEntry;
  D3D12DDI_NODE_IO_KIND_0084      InputNodeIOKind;
  UINT                            InputNodeIOFlags;
  UINT                            InputRecordSizeInBytes;
  UINT                            InputMaxRecordArraySize;
  UINT                            GroupSharedUsageInBytes;
  UINT                            MaxRecursionDepth;
  const UINT                      *pLocalRootArgumentsTableIndex;
  const UINT                      *pShareInputOfNodeIndex;
  UINT                            NumInputNodeIndices;
  const UINT                      *pInputNodeIndices;
  UINT                            NumNodesSharingInputWithThisNode;
  const UINT                      *pIndicesOfNodesSharingInputWithThisNode;
  UINT                            NumOutputs;
  const D3D12DDI_NODE_OUTPUT_0084 *pOutputs;
} D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0084;