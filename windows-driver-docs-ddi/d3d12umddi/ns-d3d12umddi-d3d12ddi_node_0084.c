typedef struct D3D12DDI_NODE_0084 {
  UINT                    NodeIndex;
  D3D12DDI_NODE_TYPE_0084 NodeType;
  union {
    D3D12DDI_SHADER_NODE_0084 Shader;
  };
} D3D12DDI_NODE_0084;