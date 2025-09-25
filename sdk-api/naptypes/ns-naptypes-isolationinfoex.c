typedef struct tagIsolationInfoEx {
  IsolationState         isolationState;
  ExtendedIsolationState extendedIsolationState;
  ProbationTime          probEndTime;
  CountedString          failureUrl;
} IsolationInfoEx;