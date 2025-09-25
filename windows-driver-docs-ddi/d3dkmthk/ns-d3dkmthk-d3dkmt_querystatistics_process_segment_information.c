typedef struct _D3DKMT_QUERYSTATISTICS_PROCESS_SEGMENT_INFORMATION {
#if ...
  D3DKMT_ALIGN64 ULONGLONG                      BytesCommitted;
#if ...
  D3DKMT_ALIGN64 ULONGLONG                      MaximumWorkingSet;
#if ...
  D3DKMT_ALIGN64 ULONGLONG                      MinimumWorkingSet;
#if ...
  ULONG                                         NbReferencedAllocationEvictedInPeriod;
  UINT                                          Padding;
#else
  ULONG                                         BytesCommitted;
#endif
#else
  ULONG                                         NbReferencedAllocationEvictedInPeriod;
#endif
#else
  ULONG                                         MaximumWorkingSet;
#endif
#else
  ULONG                                         MinimumWorkingSet;
#endif
  D3DKMT_QUERYSTATISTICS_VIDEO_MEMORY           VideoMemory;
  D3DKMT_QUERYSTATISTICS_PROCESS_SEGMENT_POLICY _Policy;
  D3DKMT_ALIGN64 UINT64                         Reserved[8];
} D3DKMT_QUERYSTATISTICS_PROCESS_SEGMENT_INFORMATION;