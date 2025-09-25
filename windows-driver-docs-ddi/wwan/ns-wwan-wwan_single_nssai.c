typedef struct _WWAN_SINGLE_NSSAI {
  UINT32 Bitmasks;
  UINT16 SliceServiceType;
  UINT16 MappedSliceServiceType;
  UINT32 SliceDifferentiator;
  UINT32 MappedSliceDifferentiator;
} WWAN_SINGLE_NSSAI, *PWWAN_SINGLE_NSSAI;