typedef struct D3D12_COMMAND_QUEUE_DESC {
  D3D12_COMMAND_LIST_TYPE   Type;
  INT                       Priority;
  D3D12_COMMAND_QUEUE_FLAGS Flags;
  UINT                      NodeMask;
} D3D12_COMMAND_QUEUE_DESC;