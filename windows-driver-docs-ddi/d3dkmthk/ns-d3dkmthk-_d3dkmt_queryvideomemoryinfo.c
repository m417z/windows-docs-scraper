typedef struct _D3DKMT_QUERYVIDEOMEMORYINFO {
  [in, opt] HANDLE                      hProcess;
  [in]      D3DKMT_HANDLE               hAdapter;
  [in]      D3DKMT_MEMORY_SEGMENT_GROUP MemorySegmentGroup;
  [out]     D3DKMT_ALIGN64 UINT64       Budget;
  [out]     D3DKMT_ALIGN64 UINT64       CurrentUsage;
  [out]     D3DKMT_ALIGN64 UINT64       CurrentReservation;
  [out]     D3DKMT_ALIGN64 UINT64       AvailableForReservation;
  [in]      UINT                        PhysicalAdapterIndex;
} D3DKMT_QUERYVIDEOMEMORYINFO;