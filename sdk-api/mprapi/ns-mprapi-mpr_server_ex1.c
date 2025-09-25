typedef struct _MPR_SERVER_EX1 {
  MPRAPI_OBJECT_HEADER         Header;
  DWORD                        fLanOnlyMode;
  DWORD                        dwUpTime;
  DWORD                        dwTotalPorts;
  DWORD                        dwPortsInUse;
  DWORD                        Reserved;
  MPRAPI_TUNNEL_CONFIG_PARAMS1 ConfigParams;
} MPR_SERVER_EX1, *PMPR_SERVER_EX1;