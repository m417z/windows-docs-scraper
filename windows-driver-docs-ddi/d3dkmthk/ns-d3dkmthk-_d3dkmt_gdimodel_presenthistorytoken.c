typedef struct _D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN {
  [in] D3DKMT_ALIGN64 ULONG64 hLogicalSurface;
  [in] D3DKMT_ALIGN64 ULONG64 hPhysicalSurface;
       RECT                   ScrollRect;
       POINT                  ScrollOffset;
  [in] D3DKMT_DIRTYREGIONS    DirtyRegions;
} D3DKMT_GDIMODEL_PRESENTHISTORYTOKEN;