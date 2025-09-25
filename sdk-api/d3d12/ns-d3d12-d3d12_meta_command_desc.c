typedef struct D3D12_META_COMMAND_DESC {
  GUID                  Id;
  LPCWSTR               Name;
  D3D12_GRAPHICS_STATES InitializationDirtyState;
  D3D12_GRAPHICS_STATES ExecutionDirtyState;
} D3D12_META_COMMAND_DESC;