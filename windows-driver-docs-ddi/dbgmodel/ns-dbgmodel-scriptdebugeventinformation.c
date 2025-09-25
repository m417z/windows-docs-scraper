struct ScriptDebugEventInformation {
  ScriptDebugEvent    DebugEvent;
  ScriptDebugPosition EventPosition;
  ScriptDebugPosition EventSpanEnd;
  union {
    struct {
      bool IsUncaught;
    } ExceptionInformation;
    struct {
      ULONG64 BreakpointId;
    } BreakpointInformation;
  } u;
};