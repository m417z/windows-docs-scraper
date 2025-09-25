typedef struct _MPIO_DEVINSTANCE_HEALTH_INFO {
  ULONG                         NumberDevInstancePackets;
  ULONG                         Reserved;
  MPIO_DEVINSTANCE_HEALTH_CLASS DevInstanceHealthPackets[1];
} MPIO_DEVINSTANCE_HEALTH_INFO, *PMPIO_DEVINSTANCE_HEALTH_INFO;