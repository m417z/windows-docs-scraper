typedef struct D3D12_DRED_ALLOCATION_NODE1 {
  const char                        *ObjectNameA;
  const wchar_t                     *ObjectNameW;
  D3D12_DRED_ALLOCATION_TYPE        AllocationType;
  const D3D12_DRED_ALLOCATION_NODE1 *pNext;
  struct                            D3D12_DRED_ALLOCATION_NODE1;
  const IUnknown                    *pObject;
} D3D12_DRED_ALLOCATION_NODE1;