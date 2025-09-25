typedef struct _DXGKARG_GETRESOURCEFORBAR {
  ULONG                           VirtualFunctionIndex;
  ULONG                           BarIndex;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR pResource;
} DXGKARG_GETRESOURCEFORBAR, *PDXGKARG_GETRESOURCEFORBAR;