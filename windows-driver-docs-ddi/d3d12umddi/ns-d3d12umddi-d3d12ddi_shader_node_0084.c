typedef struct D3D12DDI_SHADER_NODE_0084 {
  LPCWSTR                            Shader;
  D3D12DDI_NODE_PROPERTIES_TYPE_0084 PropertiesType;
  union {
    const D3D12DDI_BROADCASTING_LAUNCH_NODE_PROPERTIES_0084 *pBroadcastingLaunchNodeProperties;
    const D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0084   *pCoalescingLaunchNodeProperties;
    const D3D12DDI_THREAD_LAUNCH_NODE_PROPERTIES_0084       *pThreadLaunchNodeProperties;
  };
} D3D12DDI_SHADER_NODE_0084;