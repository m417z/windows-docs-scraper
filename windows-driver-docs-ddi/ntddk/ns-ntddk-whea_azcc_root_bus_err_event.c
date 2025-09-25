typedef struct _WHEA_AZCC_ROOT_BUS_ERR_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  BOOLEAN              MaxBusCountPassed;
  BOOLEAN              InvalidBusMSR;
} WHEA_AZCC_ROOT_BUS_ERR_EVENT, *PWHEA_AZCC_ROOT_BUS_ERR_EVENT;