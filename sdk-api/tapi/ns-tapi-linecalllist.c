typedef struct linecalllist_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwCallsNumEntries;
  DWORD dwCallsSize;
  DWORD dwCallsOffset;
} LINECALLLIST, *LPLINECALLLIST;