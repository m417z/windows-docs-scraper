typedef struct _DXGK_BUILDPAGINGBUFFER_NOTIFYALLOC {
  HANDLE                hAllocation;
  HANDLE                hKmdProcessHandle;
  DXGK_NOTIFYALLOCFLAGS Flags;
  UINT64                OffsetInBytes;
  UINT64                SizeInBytes;
  UINT64                GpuVirtualAddressAtOffset;
} DXGK_BUILDPAGINGBUFFER_NOTIFYALLOC;