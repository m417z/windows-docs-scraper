typedef struct D3D12DDI_NODE_OUTPUT_0108 {
  D3D12DDI_NODE_ID_0108                    FinalName;
  UINT                                     OutputIndex;
  D3D12DDI_NODE_IO_KIND_0108               NodeIOKind;
  UINT                                     NodeIOFlags;
  UINT                                     RecordSizeInBytes;
  BOOL                                     bAllowSparseNodes;
  const D3D12DDI_RECORD_DISPATCH_GRID_0108 *pRecordDispatchGrid;
  const UINT                               *pMaxRecords;
  const UINT                               *pMaxRecordsSharedWithOutputIndex;
  UINT                                     ArraySize;
  const D3D12DDI_NODE_LIST_ENTRY_0108      *pOutputs;
} D3D12DDI_NODE_OUTPUT_0108;