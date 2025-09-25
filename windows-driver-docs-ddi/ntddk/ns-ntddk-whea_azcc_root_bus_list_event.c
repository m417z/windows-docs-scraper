typedef struct _WHEA_AZCC_ROOT_BUS_LIST_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  UINT32               RootBusCount;
  UINT32               RootBuses[8];
} WHEA_AZCC_ROOT_BUS_LIST_EVENT, *PWHEA_AZCC_ROOT_BUS_LIST_EVENT;