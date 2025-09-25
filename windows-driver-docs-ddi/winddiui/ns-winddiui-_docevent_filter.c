typedef struct _DOCEVENT_FILTER {
  UINT  cbSize;
  UINT  cElementsAllocated;
  UINT  cElementsNeeded;
  UINT  cElementsReturned;
  DWORD aDocEventCall[ANYSIZE_ARRAY];
} DOCEVENT_FILTER, *PDOCEVENT_FILTER;