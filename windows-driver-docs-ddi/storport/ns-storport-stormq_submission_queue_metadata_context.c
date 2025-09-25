typedef struct _STORMQ_SUBMISSION_QUEUE_METADATA_CONTEXT {
  ULONG                     Version;
  ULONG                     Reserved1;
  ULONG                     QueueId;
  ULONG                     QueueSlot;
  PVOID                     VirtualAddress;
  PSTOR_SCATTER_GATHER_LIST Sgl;
  PVOID                     Mdl;
  union {
    struct {
      ULONGLONG ReadWrite : 1;
      ULONGLONG PagingIO : 1;
      ULONGLONG Reserved : 62;
    };
    ULONGLONG AsUlonglong;
  } Flags;
} STORMQ_SUBMISSION_QUEUE_METADATA_CONTEXT, *PSTORMQ_SUBMISSION_QUEUE_METADATA_CONTEXT;