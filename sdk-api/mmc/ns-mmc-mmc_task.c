typedef struct _MMC_TASK {
  MMC_TASK_DISPLAY_OBJECT sDisplayObject;
  LPOLESTR                szText;
  LPOLESTR                szHelpString;
  MMC_ACTION_TYPE         eActionType;
  union {
    LONG_PTR nCommandID;
    LPOLESTR szActionURL;
    LPOLESTR szScript;
  };
} MMC_TASK;