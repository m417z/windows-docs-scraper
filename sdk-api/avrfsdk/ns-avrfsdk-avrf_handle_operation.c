typedef struct _AVRF_HANDLE_OPERATION {
  ULONG64                    Handle;
  ULONG                      ProcessId;
  ULONG                      ThreadId;
  ULONG                      OperationType;
  ULONG                      Spare0;
  AVRF_BACKTRACE_INFORMATION BackTraceInformation;
} AVRF_HANDLE_OPERATION, *PAVRF_HANDLE_OPERATION;