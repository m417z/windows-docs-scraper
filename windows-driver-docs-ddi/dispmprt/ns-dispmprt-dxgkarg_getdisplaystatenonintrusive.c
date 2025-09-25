typedef struct _DXGKARG_GETDISPLAYSTATE_NONINTRUSIVE {
  UINT                           NumOfTargets;
  UINT                           SizeOfDisplayStateNonIntrusiveElement;
  DXGK_DISPLAYSTATE_NONINTRUSIVE **ppDisplayStateNonIntrusive;
} DXGKARG_GETDISPLAYSTATENONINTRUSIVE, *PDXGKARG_GETDISPLAYSTATENONINTRUSIVE;