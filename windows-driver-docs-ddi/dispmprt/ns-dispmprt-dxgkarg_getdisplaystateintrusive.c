typedef struct _DXGKARG_GETDISPLAYSTATE_INTRUSIVE {
  UINT                        NumOfTargets;
  UINT                        SizeOfDisplayStateIntrusiveElement;
  DXGK_DISPLAYSTATE_INTRUSIVE **ppDisplayStateIntrusive;
} DXGKARG_GETDISPLAYSTATEINTRUSIVE, *PDXGKARG_GETDISPLAYSTATEINTRUSIVE;