typedef struct D3D12DDIARG_CREATEHEAP_0001 {
  UINT64                     ByteSize;
  UINT64                     Alignment;
  D3D12DDI_MEMORY_POOL       MemoryPool;
  D3D12DDI_CPU_PAGE_PROPERTY CPUPageProperty;
  D3D12DDI_HEAP_FLAGS        Flags;
  UINT                       CreationNodeMask;
  UINT                       VisibleNodeMask;
} D3D12DDIARG_CREATEHEAP_0001;