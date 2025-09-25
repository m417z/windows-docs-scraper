typedef struct _D3DKMT_SEGMENT_CAPS {
  D3DKMT_ALIGN64 UINT64       Size;
  UINT                        PageSize;
  ULONG                       SegmentId;
  BOOLEAN                     bAperture;
  BOOLEAN                     bReservedSysMem;
  D3DKMT_MEMORY_SEGMENT_GROUP BudgetGroup;
} D3DKMT_SEGMENT_CAPS;