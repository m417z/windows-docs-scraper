typedef struct _PDH_COUNTER_INFO_W {
  DWORD     dwLength;
  DWORD     dwType;
  DWORD     CVersion;
  DWORD     CStatus;
  LONG      lScale;
  LONG      lDefaultScale;
  DWORD_PTR dwUserData;
  DWORD_PTR dwQueryUserData;
  LPWSTR    szFullPath;
  union {
    PDH_DATA_ITEM_PATH_ELEMENTS_W DataItemPath;
    PDH_COUNTER_PATH_ELEMENTS_W   CounterPath;
    struct {
      LPWSTR szMachineName;
      LPWSTR szObjectName;
      LPWSTR szInstanceName;
      LPWSTR szParentInstance;
      DWORD  dwInstanceIndex;
      LPWSTR szCounterName;
    };
  };
  LPWSTR    szExplainText;
  DWORD     DataBuffer[1];
} PDH_COUNTER_INFO_W, *PPDH_COUNTER_INFO_W;