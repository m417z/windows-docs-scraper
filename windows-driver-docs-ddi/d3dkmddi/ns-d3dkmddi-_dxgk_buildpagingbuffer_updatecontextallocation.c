typedef struct _DXGK_BUILDPAGINGBUFFER_UPDATECONTEXTALLOCATION {
  D3DGPU_VIRTUAL_ADDRESS ContextAllocation;
  UINT64                 ContextAllocationSize;
  PVOID                  pDriverPrivateData;
  UINT                   DriverPrivateDataSize;
} DXGK_BUILDPAGINGBUFFER_UPDATECONTEXTALLOCATION;