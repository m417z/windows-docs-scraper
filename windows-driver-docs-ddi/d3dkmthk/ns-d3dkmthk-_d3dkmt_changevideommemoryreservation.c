typedef struct _D3DKMT_CHANGEVIDEOMMEMORYRESERVATION {
  HANDLE                      hProcess;
  D3DKMT_HANDLE               hAdapter;
  D3DKMT_MEMORY_SEGMENT_GROUP MemorySegmentGroup;
  D3DKMT_ALIGN64 UINT64       Reservation;
  UINT                        PhysicalAdapterIndex;
} D3DKMT_CHANGEVIDEOMEMORYRESERVATION;