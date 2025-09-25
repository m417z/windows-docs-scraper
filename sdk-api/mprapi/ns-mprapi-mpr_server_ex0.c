typedef struct _MPR_SERVER_EX0 {
  MPRAPI_OBJECT_HEADER         Header;
  DWORD                        fLanOnlyMode;
  DWORD                        dwUpTime;
  DWORD                        dwTotalPorts;
  DWORD                        dwPortsInUse;
  DWORD                        Reserved;
  MPRAPI_TUNNEL_CONFIG_PARAMS0 ConfigParams;
} MPR_SERVER_EX0, *PMPR_SERVER_EX0;