typedef struct D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION {
  const D3D12_STATE_SUBOBJECT *pSubobjectToAssociate;
  UINT                        NumExports;
  LPCWSTR                     *pExports;
} D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION;