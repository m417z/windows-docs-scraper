typedef struct tagIsolationInfo {
  IsolationState isolationState;
  ProbationTime  probEndTime;
  CountedString  failureUrl;
} IsolationInfo;