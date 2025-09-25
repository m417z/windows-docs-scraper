void ClearUnorderedAccessViewUint(
  D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
  D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
  ID3D12Resource              *pResource,
  const UINT [4]              Values,
  UINT                        NumRects,
  const D3D12_RECT            *pRects
);