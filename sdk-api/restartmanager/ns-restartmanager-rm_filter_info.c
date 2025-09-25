typedef struct _RM_FILTER_INFO {
  RM_FILTER_ACTION  FilterAction;
  RM_FILTER_TRIGGER FilterTrigger;
  DWORD             cbNextOffset;
  union {
    LPWSTR            strFilename;
    RM_UNIQUE_PROCESS Process;
    LPWSTR            strServiceShortName;
  };
} RM_FILTER_INFO, *PRM_FILTER_INFO;