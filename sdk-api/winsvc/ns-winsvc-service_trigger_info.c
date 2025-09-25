typedef struct _SERVICE_TRIGGER_INFO {
  DWORD            cTriggers;
  PSERVICE_TRIGGER pTriggers;
  PBYTE            pReserved;
} SERVICE_TRIGGER_INFO, *PSERVICE_TRIGGER_INFO;