typedef struct D3D12_STATE_OBJECT_DESC {
  D3D12_STATE_OBJECT_TYPE     Type;
  UINT                        NumSubobjects;
  const D3D12_STATE_SUBOBJECT *pSubobjects;
} D3D12_STATE_OBJECT_DESC;