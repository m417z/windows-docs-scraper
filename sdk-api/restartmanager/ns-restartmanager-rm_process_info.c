typedef struct _RM_PROCESS_INFO {
  RM_UNIQUE_PROCESS Process;
  WCHAR             strAppName[CCH_RM_MAX_APP_NAME + 1];
  WCHAR             strServiceShortName[CCH_RM_MAX_SVC_NAME + 1];
  RM_APP_TYPE       ApplicationType;
  ULONG             AppStatus;
  DWORD             TSSessionId;
  BOOL              bRestartable;
} RM_PROCESS_INFO, *PRM_PROCESS_INFO;