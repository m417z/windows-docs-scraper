typedef struct _DXGKARG_GETMMIORANGES {
  ULONG              VirtualFunctionIndex;
  ULONG              BarIndex;
  ULONG              NumRanges;
  DXGK_MMIORANGEINFO *pMmioRanges;
} DXGKARG_GETMMIORANGES, *PDXGKARG_GETMMIORANGES;