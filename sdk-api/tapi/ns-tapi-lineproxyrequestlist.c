typedef struct lineproxyrequestlist_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumEntries;
  DWORD dwListSize;
  DWORD dwListOffset;
} LINEPROXYREQUESTLIST, *LPLINEPROXYREQUESTLIST;