typedef enum _FsrmCollectionState {
  FsrmCollectionState_Fetching = 1,
  FsrmCollectionState_Committing = 2,
  FsrmCollectionState_Complete = 3,
  FsrmCollectionState_Cancelled = 4
} FsrmCollectionState;