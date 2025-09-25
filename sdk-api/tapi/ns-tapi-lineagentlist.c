typedef struct lineagentlist_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumEntries;
  DWORD dwListSize;
  DWORD dwListOffset;
} LINEAGENTLIST, *LPLINEAGENTLIST;