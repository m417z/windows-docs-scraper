typedef enum _DFS_TARGET_PRIORITY_CLASS {
  DfsInvalidPriorityClass = -1,
  DfsSiteCostNormalPriorityClass = 0,
  DfsGlobalHighPriorityClass,
  DfsSiteCostHighPriorityClass,
  DfsSiteCostLowPriorityClass,
  DfsGlobalLowPriorityClass
} DFS_TARGET_PRIORITY_CLASS;