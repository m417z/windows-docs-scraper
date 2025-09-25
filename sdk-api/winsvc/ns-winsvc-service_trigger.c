typedef struct _SERVICE_TRIGGER {
  DWORD                               dwTriggerType;
  DWORD                               dwAction;
  GUID                                *pTriggerSubtype;
  DWORD                               cDataItems;
  PSERVICE_TRIGGER_SPECIFIC_DATA_ITEM pDataItems;
} SERVICE_TRIGGER, *PSERVICE_TRIGGER;