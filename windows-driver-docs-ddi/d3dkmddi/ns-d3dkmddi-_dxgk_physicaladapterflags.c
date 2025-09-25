typedef struct _DXGK_PHYSICALADAPTERFLAGS {
  union {
    struct {
      UINT IoMmuSupported : 1;
      UINT GpuMmuSupported : 1;
      UINT MovePagingSupported : 1;
      UINT VPRPagingContextRequired : 1;
      UINT AllowHardwareProtectedNoVpr : 1;
      UINT VirtualCopyEngineSupported : 1;
      UINT GpuVaIommuRequired : 1;
      UINT GpuVaIommuGlobalRequired : 1;
      UINT GpuVaIommuCacheCoherent : 1;
#if ...
      UINT Reserved : 23;
#elif
      UINT Reserved : 26;
#elif
      UINT Reserved : 27;
#elif
      UINT Reserved : 28;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_PHYSICALADAPTERFLAGS;