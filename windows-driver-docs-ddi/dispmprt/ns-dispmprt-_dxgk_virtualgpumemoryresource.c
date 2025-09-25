typedef struct _DXGK_VIRTUALGPUMEMORYRESOURCE {
  HANDLE                    DriverAllocationHandle;
  DXGK_GPU_PHYSICAL_ADDRESS AllocationAddress;
  UINT64                    AllocationSize;
} DXGK_VIRTUALGPUMEMORYRESOURCE, *PDXGK_VIRTUALGPUMEMORYRESOURCE;