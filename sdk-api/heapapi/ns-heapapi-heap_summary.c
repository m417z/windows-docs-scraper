typedef struct _HEAP_SUMMARY {
  DWORD  cb;
  SIZE_T cbAllocated;
  SIZE_T cbCommitted;
  SIZE_T cbReserved;
  SIZE_T cbMaxReserve;
} HEAP_SUMMARY, *PHEAP_SUMMARY;