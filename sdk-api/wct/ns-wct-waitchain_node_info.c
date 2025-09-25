typedef struct _WAITCHAIN_NODE_INFO {
  WCT_OBJECT_TYPE   ObjectType;
  WCT_OBJECT_STATUS ObjectStatus;
  union {
    struct {
      WCHAR         ObjectName[WCT_OBJNAME_LENGTH];
      LARGE_INTEGER Timeout;
      BOOL          Alertable;
    } LockObject;
    struct {
      DWORD ProcessId;
      DWORD ThreadId;
      DWORD WaitTime;
      DWORD ContextSwitches;
    } ThreadObject;
  };
} WAITCHAIN_NODE_INFO, *PWAITCHAIN_NODE_INFO;