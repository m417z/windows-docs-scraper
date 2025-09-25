typedef struct _DXGKARG_QUERYDIRTYBITDATA {
  HANDLE MemoryBasis;
  UINT64 SubrangeIndex;
  UINT64 SubrangeOffset;
  UINT64 SubrangeSize;
  PVOID  Buffer;
  SIZE_T BufferSize;
  UINT   Flags;
} DXGKARG_QUERYDIRTYBITDATA;