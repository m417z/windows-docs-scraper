typedef struct _NDIS_SHARED_MEMORY_PARAMETERS {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    Flags;
  NDIS_RECEIVE_QUEUE_ID    QueueId;
  NDIS_HANDLE              SharedMemoryHandle;
  NODE_REQUIREMENT         PreferredNode;
  NDIS_SHARED_MEMORY_USAGE Usage;
  ULONG                    Length;
  PVOID                    VirtualAddress;
  ULONG                    SGListBufferLength;
  PSCATTER_GATHER_LIST     SGListBuffer;
  NDIS_NIC_SWITCH_VPORT_ID VPortId;
} NDIS_SHARED_MEMORY_PARAMETERS, *PNDIS_SHARED_MEMORY_PARAMETERS;