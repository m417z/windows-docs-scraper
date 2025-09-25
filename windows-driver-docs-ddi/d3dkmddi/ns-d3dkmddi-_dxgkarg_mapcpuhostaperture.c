typedef struct _DXGKARG_MAPCPUHOSTAPERTURE {
  HANDLE hAllocation;
  WORD   SegmentId;
  WORD   PhysicalAdapterIndex;
  UINT64 NumberOfPages;
  UINT32 *pCpuHostAperturePages;
  UINT64 *pMemorySegmentPages;
} DXGKARG_MAPCPUHOSTAPERTURE;