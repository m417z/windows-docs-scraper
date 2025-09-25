typedef struct lineforwardlist_tag {
  DWORD       dwTotalSize;
  DWORD       dwNumEntries;
  LINEFORWARD ForwardList[1];
} LINEFORWARDLIST, *LPLINEFORWARDLIST;