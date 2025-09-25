typedef struct _NDIS_PROCESSOR_INFO_EX {
  PROCESSOR_NUMBER ProcNum;
  ULONG            SocketId;
  ULONG            CoreId;
  ULONG            HyperThreadId;
  USHORT           NodeId;
  USHORT           NodeDistance;
} NDIS_PROCESSOR_INFO_EX, *PNDIS_PROCESSOR_INFO_EX;