typedef struct _TXFS_MODIFY_RM {
  DWORD     Flags;
  DWORD     LogContainerCountMax;
  DWORD     LogContainerCountMin;
  DWORD     LogContainerCount;
  DWORD     LogGrowthIncrement;
  DWORD     LogAutoShrinkPercentage;
  DWORDLONG Reserved;
  WORD      LoggingMode;
} TXFS_MODIFY_RM, *PTXFS_MODIFY_RM;