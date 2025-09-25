typedef struct _DXGK_ADL {
  UINT32         PageCount;
  DXGK_ADL_FLAGS Flags;
  union {
    DXGK_PAGE_NUMBER       BasePageNumber;
    const DXGK_PAGE_NUMBER *Pages;
  };
} DXGK_ADL;