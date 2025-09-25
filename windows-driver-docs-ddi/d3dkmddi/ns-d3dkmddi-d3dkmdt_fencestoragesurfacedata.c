typedef struct _D3DKMDT_FENCESTORAGESURFACEDATA {
  UINT                          PhysicalAdapterIndex;
  DXGKARG_FENCESTORAGEVALUETYPE FenceStorageValueType;
  D3DDDI_NATIVEFENCE_TYPE       FenceStorageType;
  UINT                          PrivateDriverDataSize;
  BYTE                          *pPrivateDriverData;
  DXGKARG_FENCESTORAGEFLAGS     Flags;
  UINT                          Reserved;
  DXGK_ALLOCATIONINFO           AllocationInfo;
} D3DKMDT_FENCESTORAGESURFACEDATA;