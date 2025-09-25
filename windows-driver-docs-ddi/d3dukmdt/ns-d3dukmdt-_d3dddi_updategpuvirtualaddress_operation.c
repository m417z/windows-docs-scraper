typedef struct _D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION {
  D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION_TYPE OperationType;
  union {
    struct {
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS BaseAddress;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T          SizeInBytes;
      D3DKMT_HANDLE                         hAllocation;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T          AllocationOffsetInBytes;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T          AllocationSizeInBytes;
    } Map;
    struct {
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS   BaseAddress;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T            SizeInBytes;
      D3DKMT_HANDLE                           hAllocation;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T            AllocationOffsetInBytes;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T            AllocationSizeInBytes;
      D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE Protection;
      D3DKMT_ALIGN64 UINT64                   DriverProtection;
    } MapProtect;
    struct {
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS   BaseAddress;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T            SizeInBytes;
      D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE Protection;
    } Unmap;
    struct {
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS SourceAddress;
      D3DKMT_ALIGN64 D3DGPU_SIZE_T          SizeInBytes;
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS DestAddress;
    } Copy;
  };
} D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION;