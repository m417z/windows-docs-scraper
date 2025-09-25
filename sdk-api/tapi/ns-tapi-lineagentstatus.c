typedef struct lineagentstatus_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumEntries;
  DWORD dwGroupListSize;
  DWORD dwGroupListOffset;
  DWORD dwState;
  DWORD dwNextState;
  DWORD dwActivityID;
  DWORD dwActivitySize;
  DWORD dwActivityOffset;
  DWORD dwAgentFeatures;
  DWORD dwValidStates;
  DWORD dwValidNextStates;
} LINEAGENTSTATUS, *LPLINEAGENTSTATUS;