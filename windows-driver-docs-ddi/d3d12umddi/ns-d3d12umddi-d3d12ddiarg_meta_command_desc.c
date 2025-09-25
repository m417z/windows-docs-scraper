typedef struct D3D12DDIARG_META_COMMAND_DESC {
  GUID                     Id;
  LPCWSTR                  Name;
  D3D12DDI_GRAPHICS_STATES InitializationDirtyState;
  D3D12DDI_GRAPHICS_STATES ExecutionDirtyState;
} D3D12DDIARG_META_COMMAND_DESC;