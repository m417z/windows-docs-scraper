typedef struct D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY {
  D3D12_COMMAND_LIST_TYPE CommandListType;
  UINT                    Priority;
  BOOL                    PriorityForTypeIsSupported;
} D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY;