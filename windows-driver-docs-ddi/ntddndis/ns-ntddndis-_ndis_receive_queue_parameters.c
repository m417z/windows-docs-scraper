typedef struct _NDIS_RECEIVE_QUEUE_PARAMETERS {
  NDIS_OBJECT_HEADER          Header;
  ULONG                       Flags;
  NDIS_RECEIVE_QUEUE_TYPE     QueueType;
  NDIS_RECEIVE_QUEUE_ID       QueueId;
  NDIS_RECEIVE_QUEUE_GROUP_ID QueueGroupId;
  GROUP_AFFINITY              ProcessorAffinity;
  ULONG                       NumSuggestedReceiveBuffers;
  ULONG                       MSIXTableEntry;
  ULONG                       LookaheadSize;
  NDIS_VM_NAME                VmName;
  NDIS_QUEUE_NAME             QueueName;
  ULONG                       PortId;
  ULONG                       InterruptCoalescingDomainId;
  NDIS_QOS_SQ_ID              QosSqId;
} NDIS_RECEIVE_QUEUE_PARAMETERS, *PNDIS_RECEIVE_QUEUE_PARAMETERS;