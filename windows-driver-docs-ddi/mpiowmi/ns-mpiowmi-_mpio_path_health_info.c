typedef struct _MPIO_PATH_HEALTH_INFO {
  ULONG                  NumberPathPackets;
  ULONG                  Reserved;
  MPIO_PATH_HEALTH_CLASS PathHealthPackets[1];
} MPIO_PATH_HEALTH_INFO, *PMPIO_PATH_HEALTH_INFO;