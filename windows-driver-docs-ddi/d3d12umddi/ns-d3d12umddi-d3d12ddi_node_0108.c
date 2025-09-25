typedef struct _D3D12DDI_NODE_0108 {
  UINT                    VersionAdded;
  D3D12DDI_NODE_TYPE_0108 NodeType;
  union {
    D3D12DDI_SHADER_NODE_0108 Shader;
  };
} D3D12DDI_NODE_0108;