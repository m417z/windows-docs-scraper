typedef struct _FSRTL_ADVANCED_FCB_HEADER {
  FSRTL_COMMON_FCB_HEADER          DUMMYSTRUCTNAME;
  PFAST_MUTEX                      FastMutex;
  LIST_ENTRY                       FilterContexts;
  EX_PUSH_LOCK                     PushLock;
  PVOID                            *FileContextSupportPointer;
  union {
    OPLOCK Oplock;
    PVOID  ReservedForRemote;
  };
  PVOID                            AePushLock;
  PVOID                            ReservedContextLegacy;
  ULONG                            BypassIoOpenCount;
  struct _FSRTL_PER_STREAM_CONTEXT *ReservedContext;
} FSRTL_ADVANCED_FCB_HEADER;