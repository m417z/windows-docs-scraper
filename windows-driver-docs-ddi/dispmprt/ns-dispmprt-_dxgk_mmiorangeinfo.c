typedef struct _DXGK_MMIORANGEINFO {
  ULONG64 BasePageNumber;
  ULONG64 BasePhysicalPageNumber;
  UCHAR   BasePhysicalResourceNumber;
  BOOLEAN InterceptReads;
  BOOLEAN InterceptWrites;
  ULONG   PageCount;
} DXGK_MMIORANGEINFO, *PDXGK_MMIORANGEINFO;