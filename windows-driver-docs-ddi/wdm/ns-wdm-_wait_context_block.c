typedef struct _WAIT_CONTEXT_BLOCK {
  union {
    KDEVICE_QUEUE_ENTRY WaitQueueEntry;
    struct {
      LIST_ENTRY DmaWaitEntry;
      ULONG      NumberOfChannels;
      ULONG      SyncCallback : 1;
      ULONG      DmaContext : 1;
      ULONG      ZeroMapRegisters : 1;
      ULONG      Reserved : 9;
      ULONG      NumberOfRemapPages : 20;
    };
  };
  PDRIVER_CONTROL DeviceRoutine;
  PVOID           DeviceContext;
  ULONG           NumberOfMapRegisters;
  PVOID           DeviceObject;
  PVOID           CurrentIrp;
  PKDPC           BufferChainingDpc;
} WAIT_CONTEXT_BLOCK, *PWAIT_CONTEXT_BLOCK;