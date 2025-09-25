typedef struct D3D12_DRED_ALLOCATION_NODE {
  const char                       *ObjectNameA;
  const wchar_t                    *ObjectNameW;
  D3D12_DRED_ALLOCATION_TYPE       AllocationType;
  const D3D12_DRED_ALLOCATION_NODE *pNext;
  struct                           D3D12_DRED_ALLOCATION_NODE;
} D3D12_DRED_ALLOCATION_NODE;