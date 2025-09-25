typedef struct _DXGK_PAGE_TABLE_LEVEL_DESC {
  UINT PageTableIndexBitCount;
  UINT PageTableSegmentId;
  UINT PagingProcessPageTableSegmentId;
  UINT PageTableSizeInBytes;
  UINT PageTableAlignmentInBytes;
} DXGK_PAGE_TABLE_LEVEL_DESC;