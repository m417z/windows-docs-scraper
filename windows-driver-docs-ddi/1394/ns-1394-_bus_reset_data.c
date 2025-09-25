typedef struct _BUS_RESET_DATA {
  PVOID        ResetContext;
  ULONG        GenerationCount;
  NODE_ADDRESS DeviceNodeId;
  NODE_ADDRESS LocalNodeId;
  UCHAR        SpeedToNode;
} BUS_RESET_DATA, *PBUS_RESET_DATA;