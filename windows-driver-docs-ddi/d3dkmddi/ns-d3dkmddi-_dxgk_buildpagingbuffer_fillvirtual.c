typedef struct _DXGK_BUILDPAGINGBUFFER_FILLVIRTUAL {
  HANDLE                 hAllocation;
  UINT64                 AllocationOffsetInBytes;
  UINT64                 FillSizeInBytes;
  UINT                   FillPattern;
  D3DGPU_VIRTUAL_ADDRESS DestinationVirtualAddress;
} DXGK_BUILDPAGINGBUFFER_FILLVIRTUAL;