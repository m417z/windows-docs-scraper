typedef struct _PDH_COUNTER_INFO_A {
  DWORD     dwLength;
  DWORD     dwType;
  DWORD     CVersion;
  DWORD     CStatus;
  LONG      lScale;
  LONG      lDefaultScale;
  DWORD_PTR dwUserData;
  DWORD_PTR dwQueryUserData;
  LPSTR     szFullPath;
  union {
    PDH_DATA_ITEM_PATH_ELEMENTS_A DataItemPath;
    PDH_COUNTER_PATH_ELEMENTS_A   CounterPath;
    struct {
      LPSTR szMachineName;
      LPSTR szObjectName;
      LPSTR szInstanceName;
      LPSTR szParentInstance;
      DWORD dwInstanceIndex;
      LPSTR szCounterName;
    };
  };
  LPSTR     szExplainText;
  DWORD     DataBuffer[1];
} PDH_COUNTER_INFO_A, *PPDH_COUNTER_INFO_A;