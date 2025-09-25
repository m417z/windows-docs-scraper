typedef struct D3D12DDI_RESOURCE_ALLOCATION_INFO_0022 {
  UINT64                  ResourceDataSize;
  UINT64                  AdditionalDataHeaderSize;
  UINT64                  AdditionalDataSize;
  UINT32                  ResourceDataAlignment;
  UINT32                  AdditionalDataHeaderAlignment;
  UINT32                  AdditionalDataAlignment;
  D3D12DDI_TEXTURE_LAYOUT Layout;
  UINT8                   MipLevelSwizzleTransition[5];
  UINT8                   PlaneSliceSwizzleTransition[2];
} D3D12DDI_RESOURCE_ALLOCATION_INFO_0022;