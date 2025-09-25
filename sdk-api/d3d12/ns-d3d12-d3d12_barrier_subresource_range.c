typedef struct D3D12_BARRIER_SUBRESOURCE_RANGE {
  UINT IndexOrFirstMipLevel;
  UINT NumMipLevels;
  UINT FirstArraySlice;
  UINT NumArraySlices;
  UINT FirstPlane;
  UINT NumPlanes;
} D3D12_BARRIER_SUBRESOURCE_RANGE;