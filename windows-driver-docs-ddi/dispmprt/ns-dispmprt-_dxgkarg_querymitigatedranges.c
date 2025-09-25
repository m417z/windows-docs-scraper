typedef struct _DXGKARG_QUERYMITIGATEDRANGES {
  ULONG                    VirtualFunctionIndex;
  ULONG                    BarIndex;
  ULONG                    NumRanges;
  PDXGK_MITIGATEDRANGEINFO pMitigatedRange;
} DXGKARG_QUERYMITIGATEDRANGES, *PDXGKARG_QUERYMITIGATEDRANGES;