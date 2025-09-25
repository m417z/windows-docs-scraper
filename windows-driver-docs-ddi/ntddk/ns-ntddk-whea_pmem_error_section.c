typedef struct _WHEA_PMEM_ERROR_SECTION {
  WHEA_PMEM_ERROR_SECTION_VALIDBITS ValidBits;
  UCHAR                             LocationInfo[WHEA_PMEM_ERROR_SECTION_LOCATION_INFO_SIZE];
  WHEA_ERROR_STATUS                 ErrorStatus;
  ULONG                             NFITHandle;
  ULONG                             PageRangeCount;
  WHEA_PMEM_PAGE_RANGE              PageRange[ANYSIZE_ARRAY];
} WHEA_PMEM_ERROR_SECTION, *PWHEA_PMEM_ERROR_SECTION;