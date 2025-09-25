typedef struct D3D12DDIARG_OFFERRESOURCES {
  UINT                           NumObjects;
  const D3D12DDI_HANDLE_AND_TYPE *pObjects;
  D3DDDI_OFFER_PRIORITY          Priority;
  UINT                           Reserved;
} D3D12DDIARG_OFFERRESOURCES;