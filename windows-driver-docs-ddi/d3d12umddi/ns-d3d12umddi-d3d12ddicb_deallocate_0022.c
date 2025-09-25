typedef struct D3D12DDICB_DEALLOCATE_0022 {
  HANDLE                         hResource;
  UINT                           NumAllocations;
  const D3DKMT_HANDLE            *HandleList;
  D3D12DDI_DEALLOCATE_FLAGS_0022 Flags;
} D3D12DDICB_DEALLOCATE_0022;