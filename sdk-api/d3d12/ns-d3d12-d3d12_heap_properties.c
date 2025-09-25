typedef struct D3D12_HEAP_PROPERTIES {
  D3D12_HEAP_TYPE         Type;
  D3D12_CPU_PAGE_PROPERTY CPUPageProperty;
  D3D12_MEMORY_POOL       MemoryPoolPreference;
  UINT                    CreationNodeMask;
  UINT                    VisibleNodeMask;
} D3D12_HEAP_PROPERTIES;