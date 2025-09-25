typedef struct _MGM_IF_ENTRY {
  DWORD dwIfIndex;
  DWORD dwIfNextHopAddr;
  BOOL  bIGMP;
  BOOL  bIsEnabled;
} MGM_IF_ENTRY, *PMGM_IF_ENTRY;