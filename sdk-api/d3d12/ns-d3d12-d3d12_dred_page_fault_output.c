typedef struct D3D12_DRED_PAGE_FAULT_OUTPUT {
  D3D12_GPU_VIRTUAL_ADDRESS        PageFaultVA;
  const D3D12_DRED_ALLOCATION_NODE *pHeadExistingAllocationNode;
  const D3D12_DRED_ALLOCATION_NODE *pHeadRecentFreedAllocationNode;
} D3D12_DRED_PAGE_FAULT_OUTPUT;