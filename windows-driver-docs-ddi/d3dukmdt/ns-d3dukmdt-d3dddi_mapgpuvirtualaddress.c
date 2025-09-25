typedef struct D3DDDI_MAPGPUVIRTUALADDRESS {
  D3DKMT_HANDLE                           hPagingQueue;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS   BaseAddress;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS   MinimumAddress;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS   MaximumAddress;
  D3DKMT_HANDLE                           hAllocation;
  D3DKMT_ALIGN64 D3DGPU_SIZE_T            OffsetInPages;
  D3DKMT_ALIGN64 D3DGPU_SIZE_T            SizeInPages;
  D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE Protection;
  D3DKMT_ALIGN64 UINT64                   DriverProtection;
  UINT                                    Reserved0;
  D3DKMT_ALIGN64 UINT64                   Reserved1;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS   VirtualAddress;
  D3DKMT_ALIGN64 UINT64                   PagingFenceValue;
} D3DDDI_MAPGPUVIRTUALADDRESS;