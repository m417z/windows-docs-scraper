typedef struct _IOMMU_MAP_PHYSICAL_ADDRESS {
  IOMMU_MAP_PHYSICAL_ADDRESS_TYPE MapType;
  union {
    struct {
      PMDL Mdl;
    } Mdl;
    struct {
      PHYSICAL_ADDRESS Base;
      SIZE_T           Size;
    } ContiguousRange;
    struct {
      PPFN_NUMBER PageFrame;
      SIZE_T      NumberOfPages;
    } PfnArray;
  };
} IOMMU_MAP_PHYSICAL_ADDRESS, *PIOMMU_MAP_PHYSICAL_ADDRESS;