typedef struct _MINIDUMP_CALLBACK_OUTPUT {
  union {
    ULONG   ModuleWriteFlags;
    ULONG   ThreadWriteFlags;
    ULONG   SecondaryFlags;
    struct {
      ULONG64 MemoryBase;
      ULONG   MemorySize;
    };
    struct {
      BOOL CheckCancel;
      BOOL Cancel;
    };
    HANDLE  Handle;
    struct {
      MINIDUMP_MEMORY_INFO VmRegion;
      BOOL                 Continue;
    };
    struct {
      HRESULT              VmQueryStatus;
      MINIDUMP_MEMORY_INFO VmQueryResult;
    };
    struct {
      HRESULT VmReadStatus;
      ULONG   VmReadBytesCompleted;
    };
    HRESULT Status;
  };
} MINIDUMP_CALLBACK_OUTPUT, *PMINIDUMP_CALLBACK_OUTPUT;