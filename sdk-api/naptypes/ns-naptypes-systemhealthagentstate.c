typedef struct tagSystemHealthAgentState {
  SystemHealthEntityId id;
  ResultCodes          shaResultCodes;
  FailureCategory      failureCategory;
  FixupInfo            fixupInfo;
} SystemHealthAgentState;