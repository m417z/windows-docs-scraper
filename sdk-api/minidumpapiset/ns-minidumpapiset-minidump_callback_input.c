typedef struct _MINIDUMP_CALLBACK_INPUT {
  ULONG  ProcessId;
  HANDLE ProcessHandle;
  ULONG  CallbackType;
  union {
    HRESULT                               Status;
    MINIDUMP_THREAD_CALLBACK              Thread;
    MINIDUMP_THREAD_EX_CALLBACK           ThreadEx;
    MINIDUMP_MODULE_CALLBACK              Module;
    MINIDUMP_INCLUDE_THREAD_CALLBACK      IncludeThread;
    MINIDUMP_INCLUDE_MODULE_CALLBACK      IncludeModule;
    MINIDUMP_IO_CALLBACK                  Io;
    MINIDUMP_READ_MEMORY_FAILURE_CALLBACK ReadMemoryFailure;
    ULONG                                 SecondaryFlags;
    MINIDUMP_VM_QUERY_CALLBACK            VmQuery;
    MINIDUMP_VM_PRE_READ_CALLBACK         VmPreRead;
    MINIDUMP_VM_POST_READ_CALLBACK        VmPostRead;
  };
} MINIDUMP_CALLBACK_INPUT, *PMINIDUMP_CALLBACK_INPUT;