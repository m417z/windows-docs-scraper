typedef struct _DXGK_IOMMU_CAPS {
  union {
    struct {
      UINT32 IommuIsolationSupported : 1;
      UINT32 IommuIsolationRequired : 1;
      UINT32 DmaRemappingSupported : 1;
      UINT32 GpuVaIommuRequired : 1;
      UINT32 GpuVaIommuGlobalRequired : 1;
      UINT32 Reserved : 27;
    };
    UINT32 Value;
  };
} DXGK_IOMMU_CAPS;