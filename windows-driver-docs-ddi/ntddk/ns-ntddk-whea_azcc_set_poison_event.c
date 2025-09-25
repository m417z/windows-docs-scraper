typedef struct _WHEA_AZCC_SET_POISON_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  UINT32               Bus;
  BOOLEAN              ReadSuccess;
  BOOLEAN              WriteSuccess;
  BOOLEAN              IsEnable;
} WHEA_AZCC_SET_POISON_EVENT, *PWHEA_AZCC_SET_POISON_EVENT;