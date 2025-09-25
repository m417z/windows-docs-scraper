typedef struct D3D12_VIDEO_EXTENSION_COMMAND_INFO {
  GUID                             CommandId;
  LPCWSTR                          Name;
  D3D12_COMMAND_LIST_SUPPORT_FLAGS CommandListSupportFlags;
} D3D12_VIDEO_EXTENSION_COMMAND_INFO;