typedef struct lineagentgroupentry_tag {
  struct {
    DWORD dwGroupID1;
    DWORD dwGroupID2;
    DWORD dwGroupID3;
    DWORD dwGroupID4;
  } GroupID;
  DWORD  dwNameSize;
  DWORD  dwNameOffset;
} LINEAGENTGROUPENTRY, *LPLINEAGENTGROUPENTRY;