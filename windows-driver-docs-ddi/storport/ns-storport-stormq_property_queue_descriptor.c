typedef struct _STORMQ_PROPERTY_QUEUE_DESCRIPTOR {
  ULONG                 Version;
  ULONG                 QueueId;
  ULONG                 NumberOfElements;
  ULONG                 Reserved;
  struct {
    ULONGLONG IsSubmissionQueue : 1;
    ULONGLONG Reserved : 63;
  } Flags;
  PVOID                 VirtualAddress;
  STOR_PHYSICAL_ADDRESS PhysicalAddress;
} STORMQ_PROPERTY_QUEUE_DESCRIPTOR, *PSTORMQ_PROPERTY_QUEUE_DESCRIPTOR;