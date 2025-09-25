typedef struct _SERVICE_FAILURE_ACTIONSW {
  DWORD     dwResetPeriod;
  LPWSTR    lpRebootMsg;
  LPWSTR    lpCommand;
  DWORD     cActions;
  SC_ACTION *lpsaActions;
} SERVICE_FAILURE_ACTIONSW, *LPSERVICE_FAILURE_ACTIONSW;