typedef struct _NDIS_RECEIVE_QUEUE_INFO {
  NDIS_OBJECT_HEADER                   Header;
  ULONG                                Flags;
  NDIS_RECEIVE_QUEUE_TYPE              QueueType;
  NDIS_RECEIVE_QUEUE_ID                QueueId;
  NDIS_RECEIVE_QUEUE_GROUP_ID          QueueGroupId;
  NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE QueueState;
  GROUP_AFFINITY                       ProcessorAffinity;
  ULONG                                NumSuggestedReceiveBuffers;
  ULONG                                MSIXTableEntry;
  ULONG                                LookaheadSize;
  NDIS_VM_NAME                         VmName;
  NDIS_QUEUE_NAME                      QueueName;
  ULONG                                NumFilters;
  ULONG                                InterruptCoalescingDomainId;
} NDIS_RECEIVE_QUEUE_INFO, *PNDIS_RECEIVE_QUEUE_INFO;