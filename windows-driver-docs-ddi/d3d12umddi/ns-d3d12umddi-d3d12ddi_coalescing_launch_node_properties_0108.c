typedef struct D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0108 {
  D3D12DDI_NODE_ID_0108               FinalName;
  BOOL                                bProgramEntry;
  D3D12DDI_NODE_IO_KIND_0108          InputNodeIOKind;
  UINT                                InputNodeIOFlags;
  UINT                                InputRecordSizeInBytes;
  UINT                                InputMaxRecordArraySize;
  UINT                                GroupSharedUsageInBytes;
  UINT                                MaxRecursionDepth;
  const UINT                          *pLocalRootArgumentsTableIndex;
  const D3D12DDI_NODE_0108            *pShareInputOfNode;
  const D3D12DDI_NODE_LIST_ENTRY_0108 *pInputNodes;
  const D3D12DDI_NODE_LIST_ENTRY_0108 *pNodesSharingInputWithThisNode;
  UINT                                NumOutputs;
  const D3D12DDI_NODE_OUTPUT_0108     *pOutputs;
} D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0108;