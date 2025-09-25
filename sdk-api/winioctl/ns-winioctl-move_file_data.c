typedef struct {
  HANDLE        FileHandle;
  LARGE_INTEGER StartingVcn;
  LARGE_INTEGER StartingLcn;
  DWORD         ClusterCount;
} MOVE_FILE_DATA, *PMOVE_FILE_DATA;