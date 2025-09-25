typedef struct _PROCESSOR_GROUP_INFO {
  BYTE      MaximumProcessorCount;
  BYTE      ActiveProcessorCount;
  BYTE      Reserved[38];
  KAFFINITY ActiveProcessorMask;
} PROCESSOR_GROUP_INFO, *PPROCESSOR_GROUP_INFO;