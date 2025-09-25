typedef struct linequeuelist_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumEntries;
  DWORD dwListSize;
  DWORD dwListOffset;
} LINEQUEUELIST, *LPLINEQUEUELIST;