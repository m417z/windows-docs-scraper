typedef struct _DXGK_BUILDPAGINGBUFFER_TRANSFERVIRTUAL {
  HANDLE                         hAllocation;
  UINT64                         AllocationOffsetInBytes;
  UINT64                         TransferSizeInBytes;
  D3DGPU_VIRTUAL_ADDRESS         SourceVirtualAddress;
  D3DGPU_VIRTUAL_ADDRESS         DestinationVirtualAddress;
  D3DGPU_VIRTUAL_ADDRESS         SourcePageTable;
  DXGK_MEMORY_TRANSFER_DIRECTION TransferDirection;
  DXGK_TRANSFERVIRTUALFLAGS      Flags;
  D3DGPU_VIRTUAL_ADDRESS         DestinationPageTable;
} DXGK_BUILDPAGINGBUFFER_TRANSFERVIRTUAL;