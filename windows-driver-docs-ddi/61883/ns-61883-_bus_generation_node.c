typedef struct _BUS_GENERATION_NODE {
  OUT ULONG        GenerationCount;
  OUT NODE_ADDRESS LocalNodeAddress;
  OUT NODE_ADDRESS DeviceNodeAddress;
} BUS_GENERATION_NODE, *PBUS_GENERATION_NODE;