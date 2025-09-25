typedef struct _MAPPING_PROPERTY_BAG {
  size_t              Size;
  PMAPPING_DATA_RANGE prgResultRanges;
  DWORD               dwRangesCount;
  LPVOID              pServiceData;
  DWORD               dwServiceDataSize;
  LPVOID              pCallerData;
  DWORD               dwCallerDataSize;
  LPVOID              pContext;
} MAPPING_PROPERTY_BAG, *PMAPPING_PROPERTY_BAG;