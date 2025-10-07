typedef struct ORPC_INIT_ARGS {
  IOrpcDebugNotify *lpIntfOrpcDebug;
  void             *pvPSN;
  DWORD            *dwReserved1;
  DWORD            *dwReserved2;
} ORPC_INIT_ARGS, *LPORPC_INIT_ARGS;