typedef struct D3D12_META_COMMAND_PARAMETER_DESC {
  LPCWSTR                            Name;
  D3D12_META_COMMAND_PARAMETER_TYPE  Type;
  D3D12_META_COMMAND_PARAMETER_FLAGS Flags;
  D3D12_RESOURCE_STATES              RequiredResourceState;
  UINT                               StructureOffset;
} D3D12_META_COMMAND_PARAMETER_DESC;