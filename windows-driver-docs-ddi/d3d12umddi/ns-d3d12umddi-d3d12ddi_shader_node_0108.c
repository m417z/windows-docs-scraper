typedef struct D3D12DDI_SHADER_NODE_0108 {
  LPCWSTR                            Shader;
  D3D12DDI_NODE_PROPERTIES_TYPE_0108 PropertiesType;
  union {
    const D3D12DDI_BROADCASTING_LAUNCH_NODE_PROPERTIES_0108 *pBroadcastingLaunchNodeProperties;
    const D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0108   *pCoalescingLaunchNodeProperties;
    const D3D12DDI_THREAD_LAUNCH_NODE_PROPERTIES_0108       *pThreadLaunchNodeProperties;
  };
} D3D12DDI_SHADER_NODE_0108;