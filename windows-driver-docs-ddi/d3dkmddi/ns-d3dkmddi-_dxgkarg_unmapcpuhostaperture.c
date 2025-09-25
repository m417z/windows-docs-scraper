typedef struct _DXGKARG_UNMAPCPUHOSTAPERTURE {
  UINT64 NumberOfPages;
  UINT32 *pCpuHostAperturePages;
  WORD   SegmentId;
  WORD   PhysicalAdapterIndex;
} DXGKARG_UNMAPCPUHOSTAPERTURE;