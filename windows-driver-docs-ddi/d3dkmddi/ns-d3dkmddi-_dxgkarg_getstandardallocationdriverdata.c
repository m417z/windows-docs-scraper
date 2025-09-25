typedef struct _DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA {
  D3DKMDT_STANDARDALLOCATION_TYPE StandardAllocationType;
  union {
    D3DKMDT_SHAREDPRIMARYSURFACEDATA *pCreateSharedPrimarySurfaceData;
    D3DKMDT_SHADOWSURFACEDATA        *pCreateShadowSurfaceData;
    D3DKMDT_STAGINGSURFACEDATA       *pCreateStagingSurfaceData;
    D3DKMDT_GDISURFACEDATA           *pCreateGdiSurfaceData;
    D3DKMDT_VIRTUALGPUSURFACEDATA    *pCreateVirtualGpuSurfaceData;
    D3DKMDT_FENCESTORAGESURFACEDATA  *pCreateFenceStorageData;
  };
  VOID                            *pAllocationPrivateDriverData;
  UINT                            AllocationPrivateDriverDataSize;
  VOID                            *pResourcePrivateDriverData;
  UINT                            ResourcePrivateDriverDataSize;
  UINT                            PhysicalAdapterIndex;
} DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA;